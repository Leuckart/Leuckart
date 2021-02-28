/**************************************************
	> File Name:  Tools.h
	> Author:     Leuckart
	> Time:       2019-12-19 17:17
**************************************************/

#ifndef TOOLS_H_
#define TOOLS_H_

#define CACHE_LINE_SIZE 64
#define __USE_GNU

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <errno.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <poll.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>
#include <sched.h>
#include <sys/param.h>

/* Exclusive locking primitives. */
typedef pthread_mutex_t spinlock_t;

static __inline__ void spin_lock_init(spinlock_t *sp)
{
	int ret;

retry:
	ret = pthread_mutex_init(sp, NULL);
	if (ret)
	{
		if (ret == EINTR)
			goto retry;
		fprintf(stderr, "spin_lock_init:pthread_mutex_init %d\n", ret);
		abort();
	}
}

static __inline__ void spin_lock(spinlock_t *sp)
{
	int en;

	en = pthread_mutex_lock(sp);
	if (en != 0)
	{
		fprintf(stderr, "pthread_mutex_lock: %s\n", strerror(en));
		perror("spin_lock:pthread_mutex_lock");
		abort();
	}
}

static __inline__ void spin_unlock(spinlock_t *sp)
{
	int en;

	en = pthread_mutex_unlock(sp);
	if (en != 0)
	{
		fprintf(stderr, "pthread_mutex_unlock: %s\n", strerror(en));
		abort();
	}
}

/* Thread creation/destruction primitives. */
typedef pthread_t thread_id_t;

#define NR_THREADS 512

#define __THREAD_ID_MAP_EMPTY 0
#define __THREAD_ID_MAP_WAITING 1
thread_id_t __thread_id_map[NR_THREADS];
spinlock_t __thread_id_map_mutex;

#define for_each_thread(t) \
	for (t = 0; t < NR_THREADS; t++)

#define for_each_tid(t, tid)                                           \
	for (t = 0; t < NR_THREADS; t++)                                   \
		if ((((tid) = __thread_id_map[t]) != __THREAD_ID_MAP_EMPTY) && \
			((tid) != __THREAD_ID_MAP_WAITING))

pthread_key_t thread_id_key;

static __inline__ int __smp_thread_id(void)
{
	int i;
	thread_id_t tid = pthread_self();

	for (i = 0; i < NR_THREADS; i++)
	{
		if (__thread_id_map[i] == tid)
		{
			long v = i + 1; /* must be non-NULL. */

			if (pthread_setspecific(thread_id_key, (void *)v) != 0)
			{
				perror("pthread_setspecific");
				exit(EXIT_FAILURE);
			}
			return i;
		}
	}
	spin_lock(&__thread_id_map_mutex);
	for (i = 0; i < NR_THREADS; i++)
	{
		if (__thread_id_map[i] == tid)
		{
			spin_unlock(&__thread_id_map_mutex);
			return i;
		}
	}
	spin_unlock(&__thread_id_map_mutex);
	fprintf(stderr, "smp_thread_id: Rogue thread, id: %d(%#x)\n",
			(int)tid, (int)tid);
	exit(EXIT_FAILURE);
}

static __inline__ int smp_thread_id(void)
{
	void *id;

	id = pthread_getspecific(thread_id_key);
	if (id == NULL)
		return __smp_thread_id();
	return (long)(id - 1);
}

static __inline__ thread_id_t create_thread(void *(*func)(void *), void *arg)
{
	thread_id_t tid;
	int i;

	spin_lock(&__thread_id_map_mutex);
	for (i = 0; i < NR_THREADS; i++)
	{
		if (__thread_id_map[i] == __THREAD_ID_MAP_EMPTY)
			break;
	}
	if (i >= NR_THREADS)
	{
		spin_unlock(&__thread_id_map_mutex);
		fprintf(stderr, "Thread limit of %d exceeded!\n", NR_THREADS);
		exit(EXIT_FAILURE);
	}
	__thread_id_map[i] = __THREAD_ID_MAP_WAITING;
	if (pthread_create(&tid, NULL, func, arg) != 0)
	{
		perror("create_thread:pthread_create");
		exit(EXIT_FAILURE);
	}
	__thread_id_map[i] = tid;
	spin_unlock(&__thread_id_map_mutex);
	return tid;
}

static __inline__ void *wait_thread(thread_id_t tid)
{
	int i;
	void *vp;

	for (i = 0; i < NR_THREADS; i++)
	{
		if (__thread_id_map[i] == tid)
			break;
	}
	if (i >= NR_THREADS)
	{
		fprintf(stderr, "wait_thread: bad tid = %d(%#x)\n",
				(int)tid, (int)tid);
		exit(EXIT_FAILURE);
	}
	if (pthread_join(tid, &vp) != 0)
	{
		perror("wait_thread:pthread_join");
		exit(EXIT_FAILURE);
	}
	__thread_id_map[i] = __THREAD_ID_MAP_EMPTY;
	return vp;
}

static __inline__ void wait_all_threads(void)
{
	int i;
	thread_id_t tid;

	for (i = 1; i < NR_THREADS; i++)
	{
		tid = __thread_id_map[i];
		if (tid != __THREAD_ID_MAP_EMPTY &&
			tid != __THREAD_ID_MAP_WAITING)
			(void)wait_thread(tid);
	}
}

/* Per-thread variables. */
#define DEFINE_PER_THREAD(type, name)                      \
	struct                                                 \
	{                                                      \
		__typeof__(type) v                                 \
			__attribute__((__aligned__(CACHE_LINE_SIZE))); \
	} __per_thread_##name[NR_THREADS];

#define per_thread(name, thread) __per_thread_##name[thread].v

#define __get_thread_var(name) per_thread(name, smp_thread_id())

#define init_per_thread(name, v)                                 \
	do                                                           \
	{                                                            \
		int __i_p_t_i;                                           \
		for (__i_p_t_i = 0; __i_p_t_i < NR_THREADS; __i_p_t_i++) \
			per_thread(name, __i_p_t_i) = v;                     \
	} while (0)

DEFINE_PER_THREAD(int, smp_processor_id);

static __inline__ int smp_processor_id(void)
{
	return __get_thread_var(smp_processor_id);
}

static __inline__ void set_smp_processor_id(int cpu)
{
	__get_thread_var(smp_processor_id) = cpu;
}

/* Initialization -- Must be called before calling any primitives. */
static __inline__ void smp_init(void)
{
	int i;

	spin_lock_init(&__thread_id_map_mutex);
	__thread_id_map[0] = pthread_self();
	for (i = 1; i < NR_THREADS; i++)
		__thread_id_map[i] = __THREAD_ID_MAP_EMPTY;
	init_per_thread(smp_processor_id, 0);
	if (pthread_key_create(&thread_id_key, NULL) != 0)
	{
		perror("pthread_key_create");
		exit(EXIT_FAILURE);
	}
}

/* Atomic data structure, initialization, and access. */

typedef struct
{
	volatile int counter;
} atomic_t;

#define ATOMIC_INIT(i) \
	{                  \
		(i)            \
	}

#define atomic_read(v) \
	__atomic_load_n(&(v)->counter, __ATOMIC_RELAXED)

#define atomic_set(v, i) \
	__atomic_store_n(&(v)->counter, (i), __ATOMIC_RELAXED)

static __inline__ void atomic_add(int i, atomic_t *v)
{
	__atomic_add_fetch(&v->counter, i, __ATOMIC_RELAXED);
}

static __inline__ void atomic_sub(int i, atomic_t *v)
{
	__atomic_sub_fetch(&v->counter, i, __ATOMIC_RELAXED);
}

static __inline__ void atomic_inc(atomic_t *v)
{
	atomic_add(1, v);
}

static __inline__ void atomic_dec(atomic_t *v)
{
	atomic_sub(1, v);
}

#endif
