/**************************************************
	> File Name:  Demo_02.01_InitRace.c
	> Author:     Leuckart
	> Time:       2019-12-18 10:25
**************************************************/

/* InitRace.c: simple program demonstrating racy initialization. */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "Tools.h"

int nkids = 1;

atomic_t counter;
atomic_t start_count;

int goflag;
#define GOFLAG_INIT 0
#define GOFLAG_START 1
#define GOFLAG_STOP 2

spinlock_t mutex;
int initialized;
DEFINE_PER_THREAD(int, doneflag);

void *init_test(void *arg)
{
	while (goflag != GOFLAG_STOP)
	{
		while (goflag == GOFLAG_INIT)
			poll(NULL, 0, 1);
		if (goflag == GOFLAG_STOP)
			break;
		atomic_inc(&start_count);
		while (atomic_read(&start_count) != nkids)
			continue;

		/* --- Lock-free checked initialization --- */
		if (!initialized)
		{
			spin_lock(&mutex);
			initialized = 1;
			atomic_inc(&counter);
			spin_unlock(&mutex);
		}
		/* --- End of lock-free checked initialization --- */

		__get_thread_var(doneflag) = 1;
		while (goflag == GOFLAG_START)
			poll(NULL, 0, 1);
		atomic_inc(&counter);
	}
	return NULL;
}

void usage(char *progname)
{
	fprintf(stderr,
			"Usage: %s [ #threads ]\n", progname);
	exit(-1);
}

int main(int argc, char *argv[])
{
	int done;
	int i;
	int iter;

	smp_init();

	if (argc > 1)
	{
		nkids = strtoul(argv[1], NULL, 0);
		if (nkids > NR_THREADS)
		{
			fprintf(stderr, "nkids = %d too large, max = %d\n",
					nkids, NR_THREADS);
			usage(argv[0]);
		}
	}
	printf("Number of threads: %d\n", nkids);

	spin_lock_init(&mutex);
	goflag = GOFLAG_INIT;
	for (i = 0; i < nkids; i++)
		create_thread(init_test, NULL);

	for (iter = 0; iter < 100; iter++)
	{
		spin_lock(&mutex);
		for_each_thread(i)
		{
			per_thread(doneflag, i) = 0;
		}
		__get_thread_var(doneflag) = 1;
		atomic_set(&counter, 0);
		atomic_set(&start_count, 0);
		initialized = 0;
		spin_unlock(&mutex);
		spin_lock(&mutex);
		goflag = GOFLAG_START;
		spin_unlock(&mutex);
		poll(NULL, 0, 1);
		done = 0;
		while (!done)
		{
			done = 1;
			for (i = 0; i < nkids; i++)
				if (!per_thread(doneflag, i))
				{
					done = 0;
					break;
				}
			poll(NULL, 0, 1);
		}
		if (atomic_read(&counter) != 1)
		{
			printf("Double initialization, counter = %d\n",
				   atomic_read(&counter));
			exit(-1);
		}
		else
		{
			printf("Iteration %d succeeded\n", iter);
		}
		spin_lock(&mutex);
		atomic_set(&counter, 0);
		spin_unlock(&mutex);
		spin_lock(&mutex);
		goflag = GOFLAG_INIT;
		while (atomic_read(&counter) < nkids)
			poll(NULL, 0, 1);
		spin_unlock(&mutex);
		spin_lock(&mutex);
		atomic_set(&counter, 0);
		spin_unlock(&mutex);
	}

	goflag = GOFLAG_STOP;

	wait_all_threads();

	exit(0);
}
