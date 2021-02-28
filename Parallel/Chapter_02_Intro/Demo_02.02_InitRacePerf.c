/**************************************************
	> File Name:  Demo_02.02_InitRacePerf.c
	> Author:     Leuckart
	> Time:       2019-12-19 15:53
**************************************************/

/* InitRacePerf.c: simple program comparing lock and flag check. */

#include "Tools.h"

spinlock_t mutex;
long long counter;
int goflag;
int initialized = 0;

void initcounter(void)
{
	spin_lock_init(&mutex);
}

void *counter_test(void *arg)
{
	long long mycounter = 0LL;

	while (goflag < 0)
		continue;
	while (goflag)
	{
		if (!initialized)
		{
			spin_lock(&mutex);
			initialized = 1;
			spin_unlock(&mutex);
		}
		mycounter++;
	}
	spin_lock(&mutex);
	counter += mycounter;
	spin_unlock(&mutex);
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
	int i;
	int nkids = 1;

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
	printf("%d ", nkids);

	goflag = -1;
	counter = 0LL;
	for (i = 0; i < nkids; i++)
		create_thread(counter_test, NULL);

	goflag = 1;
	sleep(1);
	goflag = 0;

	wait_all_threads();

	printf("count: %lld\n", counter);

	exit(0);
}
