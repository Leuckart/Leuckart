/**************************************************
	> File Name:  Demo_05.02_CountAtomic.c
	> Author:     Leuckart
	> Time:       2020-03-05 20:25
**************************************************/

/* count_atomic.c: simple atomic counter. */

#include "Tools.h"

atomic_t counter = ATOMIC_INIT(0);

static __inline__ void inc_count(void)
{
	atomic_inc(&counter);
}

static __inline__ long read_count(void)
{
	return atomic_read(&counter);
}

static __inline__ void count_init(void)
{
}

static __inline__ void count_cleanup(void)
{
}

#include "CountTorture.h"
