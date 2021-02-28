/**************************************************
	> File Name:  Demo_05.04_CountStatAtomic.c
	> Author:     Leuckart
	> Time:       2020-03-05 22:42
**************************************************/

/* count_stat_atomic.c: Per-thread atomic statistical counters. */

#include "Tools.h"

DEFINE_PER_THREAD(atomic_t, counter);

void inc_count(void)
{
	atomic_inc(&__get_thread_var(counter));
}

static __inline__ unsigned long read_count(void)
{
	int t;
	unsigned long sum = 0;

	for_each_thread(t)
		sum += atomic_read(&per_thread(counter, t));
	return sum;
}

static __inline__ void count_init(void)
{
}

static __inline__ void count_cleanup(void)
{
}

#include "CountTorture.h"
