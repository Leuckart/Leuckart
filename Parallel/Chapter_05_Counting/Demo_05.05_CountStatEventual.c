/**************************************************
	> File Name:  Demo_05.05_CountStatEventual.c
	> Author:     Leuckart
	> Time:       2020-03-05 22:50
**************************************************/

/* count_stat_eventual.c: Per-thread atomic statistical counters with "eventually consistent" semantics. */

#include "Tools.h"

DEFINE_PER_THREAD(unsigned long, counter);
unsigned long global_count;
int stopflag;

static __inline__ void inc_count(void)
{
	unsigned long *p_counter = &__get_thread_var(counter);

	WRITE_ONCE(*p_counter, *p_counter + 1);
}

static __inline__ unsigned long read_count(void)
{
	return READ_ONCE(global_count);
}

void *eventual(void *arg)
{
	int t;
	unsigned long sum;

	while (READ_ONCE(stopflag) < 3)
	{
		sum = 0;
		for_each_thread(t)
			sum += READ_ONCE(per_thread(counter, t));
		WRITE_ONCE(global_count, sum);
		poll(NULL, 0, 1);
		if (READ_ONCE(stopflag))
		{
			smp_mb();
			WRITE_ONCE(stopflag, stopflag + 1);
		}
	}
	return NULL;
}

void count_init(void)
{
	int en;
	thread_id_t tid;

	en = pthread_create(&tid, NULL, eventual, NULL);
	if (en != 0)
	{
		fprintf(stderr, "pthread_create: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}
}

void count_cleanup(void)
{
	WRITE_ONCE(stopflag, 1);
	while (READ_ONCE(stopflag) < 3)
		poll(NULL, 0, 1);
	smp_mb();
}

#include "CountTorture.h"
