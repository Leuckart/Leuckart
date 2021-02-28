/**************************************************
	> File Name:  Demo_05.06_CountEnd.c
	> Author:     Leuckart
	> Time:       2020-03-05 22:56
**************************************************/

/* count_end.c: Per-thread statistical counters that provide sum at end.
 *	Uses __thread for each thread's counter. */

#include "Tools.h"

unsigned long __thread counter = 0;
unsigned long *counterp[NR_THREADS] = {NULL};
unsigned long finalcount = 0;
DEFINE_SPINLOCK(final_mutex);

static __inline__ void inc_count(void)
{
	WRITE_ONCE(counter, counter + 1);
}

static __inline__ unsigned long read_count(void)
{
	int t;
	unsigned long sum;

	spin_lock(&final_mutex);
	sum = finalcount;
	for_each_thread(t) if (counterp[t] != NULL)
		sum += READ_ONCE(*counterp[t]);
	spin_unlock(&final_mutex);
	return sum;
}

#ifndef FCV_SNIPPET
static __inline__ void count_init(void)
{
}
#endif

void count_register_thread(unsigned long *p)
{
	int idx = smp_thread_id();

	spin_lock(&final_mutex);
	counterp[idx] = &counter;
	spin_unlock(&final_mutex);
}

void count_unregister_thread(int nthreadsexpected)
{
	int idx = smp_thread_id();

	spin_lock(&final_mutex);
	finalcount += counter;
	counterp[idx] = NULL;
	spin_unlock(&final_mutex);
}

static __inline__ void count_cleanup(void)
{
}

#define NEED_REGISTER_THREAD
#include "CountTorture.h"
