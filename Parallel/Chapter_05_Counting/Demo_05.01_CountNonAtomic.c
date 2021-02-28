/**************************************************
	> File Name:  Demo_05.01_CountNonAtomic.c
	> Author:     Leuckart
	> Time:       2020-03-05 18:02
**************************************************/

/* CountNonAtomic.c */
/* 简单的非原子计数器，在某些系统上可能是原子的 */

#include "Tools.h"

unsigned long counter = 0;

static __inline__ void inc_count(void)
{
	WRITE_ONCE(counter, READ_ONCE(counter) + 1);
}

static __inline__ unsigned long read_count(void)
{
	return READ_ONCE(counter);
}

static __inline__ void count_init(void)
{
}

static __inline__ void count_cleanup(void)
{
}

#include "CountTorture.h"
