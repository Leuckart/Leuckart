/**************************************************
	> File Name:  Demo_05.08_CountLim.c
	> Author:     Leuckart
	> Time:       2020-03-05 23:37
**************************************************/

/* count_lim.c: simple limit counter. */

#include "Tools.h"

static __inline__ void globalize_count(void);
static __inline__ void balance_count(void);

unsigned long __thread counter = 0;
unsigned long __thread countermax = 0;
unsigned long globalcountmax = 10000;
unsigned long globalcount = 0;
unsigned long globalreserve = 0;
unsigned long *counterp[NR_THREADS] = {NULL};
DEFINE_SPINLOCK(gblcnt_mutex);

static __inline__ int add_count(unsigned long delta)
{
	if (countermax - counter >= delta)
	{
		WRITE_ONCE(counter, counter + delta);
		return 1;
	}
	spin_lock(&gblcnt_mutex);
	globalize_count();
	if (globalcountmax -
			globalcount - globalreserve <
		delta)
	{
		spin_unlock(&gblcnt_mutex);
		return 0;
	}
	globalcount += delta;
	balance_count();
	spin_unlock(&gblcnt_mutex);
	return 1;
}

static __inline__ int sub_count(unsigned long delta)
{
	if (counter >= delta)
	{
		WRITE_ONCE(counter, counter - delta);
		return 1;
	}
	spin_lock(&gblcnt_mutex);
	globalize_count();
	if (globalcount < delta)
	{
		spin_unlock(&gblcnt_mutex);
		return 0;
	}
	globalcount -= delta;
	balance_count();
	spin_unlock(&gblcnt_mutex);
	return 1;
}

static __inline__ unsigned long read_count(void)
{
	int t;
	unsigned long sum;

	spin_lock(&gblcnt_mutex);
	sum = globalcount;
	for_each_thread(t) if (counterp[t] != NULL)
		sum += READ_ONCE(*counterp[t]);
	spin_unlock(&gblcnt_mutex);
	return sum;
}

static __inline__ void globalize_count(void)
{
	globalcount += counter;
	counter = 0;
	globalreserve -= countermax;
	countermax = 0;
}

static __inline__ void balance_count(void)
{
	countermax = globalcountmax -
				 globalcount - globalreserve;
	countermax /= num_online_threads();
	globalreserve += countermax;
	counter = countermax / 2;
	if (counter > globalcount)
		counter = globalcount;
	globalcount -= counter;
}

#ifndef FCV_SNIPPET
void count_init(void)
{
}
#endif

void count_register_thread(void)
{
	int idx = smp_thread_id();

	spin_lock(&gblcnt_mutex);
	counterp[idx] = &counter;
	spin_unlock(&gblcnt_mutex);
}

void count_unregister_thread(int nthreadsexpected)
{
	int idx = smp_thread_id();

	spin_lock(&gblcnt_mutex);
	globalize_count();
	counterp[idx] = NULL;
	spin_unlock(&gblcnt_mutex);
}

void count_cleanup(void)
{
}

#define NEED_REGISTER_THREAD
#include "LimTorture.h"
