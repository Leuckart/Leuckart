/**************************************************
	> File Name:  Demo_05.03_CountStat.c
	> Author:     Leuckart
	> Time:       2020-03-05 22:29
**************************************************/

/* count_stat.c: Per-thread statistical counters. */

#include "Tools.h"

DEFINE_PER_THREAD(unsigned long, counter);

static __inline__ void inc_count(void)
{
	unsigned long *p_counter = &__get_thread_var(counter);

	WRITE_ONCE(*p_counter, *p_counter + 1);
}

static __inline__ unsigned long read_count(void)
{
	int t;
	unsigned long sum = 0;

	for_each_thread(t)
		sum += READ_ONCE(per_thread(counter, t));
	return sum;
}

void count_init(void)
{
}

void count_cleanup(void)
{
}

#include "CountTorture.h"
