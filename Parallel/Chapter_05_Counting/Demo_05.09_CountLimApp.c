/**************************************************
	> File Name:  Demo_05.09_CountLimApp.c
	> Author:     Leuckart
	> Time:       2020-03-05 23:49
**************************************************/

/* count_lim_app.c: simple limit counter with degree of approximation controlled by MAX_COUNTERMAX. */

#include "Tools.h"

unsigned long __thread counter = 0;
unsigned long __thread countermax = 0;
unsigned long globalcountmax = 10000;
unsigned long globalcount = 0;
unsigned long globalreserve = 0;
unsigned long *counterp[NR_THREADS] = {NULL};
DEFINE_SPINLOCK(gblcnt_mutex);
#define MAX_COUNTERMAX 100

static void globalize_count(void)
{
	globalcount += counter;
	counter = 0;
	globalreserve -= countermax;
	countermax = 0;
}

static void balance_count(void)
{
	countermax = globalcountmax -
				 globalcount - globalreserve;
	countermax /= num_online_threads();
	if (countermax > MAX_COUNTERMAX)
		countermax = MAX_COUNTERMAX;
	globalreserve += countermax;
	counter = countermax / 2;
	if (counter > globalcount)
		counter = globalcount;
	globalcount -= counter;
}

int add_count(unsigned long delta)
{
	if (countermax - counter >= delta)
	{
		WRITE_ONCE(counter, counter + delta);
		return 1;
	}
	spin_lock(&gblcnt_mutex);
	globalize_count();
	if (globalcountmax - globalcount - globalreserve < delta)
	{
		spin_unlock(&gblcnt_mutex);
		return 0;
	}
	globalcount += delta;
	balance_count();
	spin_unlock(&gblcnt_mutex);
	return 1;
}

int sub_count(unsigned long delta)
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

unsigned long read_count(void)
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

void count_init(void)
{
}

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
