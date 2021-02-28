/**************************************************
	> File Name:  Demo_05.11_CountLimSig.c
	> Author:     Leuckart
	> Time:       2020-03-05 23:58
**************************************************/

/*
 * count_lim_sig.c: simple limit counter that uses POSIX signals
 *	to steal from other threads.
 */

#include "Tools.h"
#include <signal.h>

#define THEFT_IDLE 0
#define THEFT_REQ 1
#define THEFT_ACK 2
#define THEFT_READY 3

int __thread theft = THEFT_IDLE;
int __thread counting = 0;
unsigned long __thread counter = 0;
unsigned long __thread countermax = 0;
unsigned long globalcountmax = 10000;
unsigned long globalcount = 0;
unsigned long globalreserve = 0;
unsigned long *counterp[NR_THREADS] = {NULL};
unsigned long *countermaxp[NR_THREADS] = {NULL};
int *theftp[NR_THREADS] = {NULL};
DEFINE_SPINLOCK(gblcnt_mutex);
#define MAX_COUNTERMAX 100

static void globalize_count(void)
{
	globalcount += counter;
	counter = 0;
	globalreserve -= countermax;
	countermax = 0;
}

static void flush_local_count_sig(int unused)
{
	if (READ_ONCE(theft) != THEFT_REQ)
		return;
	smp_mb();
	WRITE_ONCE(theft, THEFT_ACK);
	if (!counting)
	{
		WRITE_ONCE(theft, THEFT_READY);
	}
	smp_mb();
}

static void flush_local_count(void)
{
	int t;
	thread_id_t tid;

	for_each_tid(t, tid) if (theftp[t] != NULL)
	{
		if (*countermaxp[t] == 0)
		{
			WRITE_ONCE(*theftp[t], THEFT_READY);
			continue;
		}
		WRITE_ONCE(*theftp[t], THEFT_REQ);
		pthread_kill(tid, SIGUSR1);
	}
	for_each_tid(t, tid)
	{
		if (theftp[t] == NULL)
			continue;
		while (READ_ONCE(*theftp[t]) != THEFT_READY)
		{
			poll(NULL, 0, 1);
			if (READ_ONCE(*theftp[t]) == THEFT_REQ)
				pthread_kill(tid, SIGUSR1);
		}
		globalcount += *counterp[t];
		*counterp[t] = 0;
		globalreserve -= *countermaxp[t];
		*countermaxp[t] = 0;
		WRITE_ONCE(*theftp[t], THEFT_IDLE);
	}
}

static void balance_count(void)
{
	countermax = globalcountmax - globalcount -
				 globalreserve;
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
	int fastpath = 0;

	WRITE_ONCE(counting, 1);
	barrier();
	if (READ_ONCE(theft) <= THEFT_REQ &&
		countermax - counter >= delta)
	{
		WRITE_ONCE(counter, counter + delta);
		fastpath = 1;
	}
	barrier();
	WRITE_ONCE(counting, 0);
	barrier();
	if (READ_ONCE(theft) == THEFT_ACK)
	{
		smp_mb();
		WRITE_ONCE(theft, THEFT_READY);
	}
	if (fastpath)
		return 1;
	spin_lock(&gblcnt_mutex);
	globalize_count();
	if (globalcountmax - globalcount -
			globalreserve <
		delta)
	{
		flush_local_count();
		if (globalcountmax - globalcount -
				globalreserve <
			delta)
		{
			spin_unlock(&gblcnt_mutex);
			return 0;
		}
	}
	globalcount += delta;
	balance_count();
	spin_unlock(&gblcnt_mutex);
	return 1;
}

int sub_count(unsigned long delta)
{
	int fastpath = 0;

	WRITE_ONCE(counting, 1);
	barrier();
	if (READ_ONCE(theft) <= THEFT_REQ &&
		counter >= delta)
	{
		WRITE_ONCE(counter, counter - delta);
		fastpath = 1;
	}
	barrier();
	WRITE_ONCE(counting, 0);
	barrier();
	if (READ_ONCE(theft) == THEFT_ACK)
	{
		smp_mb();
		WRITE_ONCE(theft, THEFT_READY);
	}
	if (fastpath)
		return 1;
	spin_lock(&gblcnt_mutex);
	globalize_count();
	if (globalcount < delta)
	{
		flush_local_count();
		if (globalcount < delta)
		{
			spin_unlock(&gblcnt_mutex);
			return 0;
		}
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
	struct sigaction sa;

	sa.sa_handler = flush_local_count_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}

void count_register_thread(void)
{
	int idx = smp_thread_id();

	spin_lock(&gblcnt_mutex);
	counterp[idx] = &counter;
	countermaxp[idx] = &countermax;
	theftp[idx] = &theft;
	spin_unlock(&gblcnt_mutex);
}

void count_unregister_thread(int nthreadsexpected)
{
	int idx = smp_thread_id();

	spin_lock(&gblcnt_mutex);
	globalize_count();
	counterp[idx] = NULL;
	countermaxp[idx] = NULL;
	theftp[idx] = NULL;
	spin_unlock(&gblcnt_mutex);
}

void count_cleanup(void)
{
}

#define NEED_REGISTER_THREAD
#include "LimTorture.h"
