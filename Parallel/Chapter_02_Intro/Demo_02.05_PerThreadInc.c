/**************************************************
	> File Name:  Demo_02.05_PerThreadInc.c
	> Author:     Leuckart
	> Time:       2019-12-19 16:01
**************************************************/

/* PerThreadInc.c: simple program demonstrating per-thread increment performance. */

#include "Tools.h"

DEFINE_PER_THREAD(int, counter);
int goflag;

void initcounter(void)
{
	init_per_thread(counter, 0);
}

void *counter_test(void *arg)
{
	while (goflag < 0)
		continue;
	while (goflag)
	{
		__get_thread_var(counter)++;
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
	int i;
	int nkids = 1;
	long long sum = 0;

	smp_init();

	if (argc > 1)
	{
		nkids = strtoul(argv[1], NULL, 0);
		if (nkids > NR_THREADS)
		{
			fprintf(stderr, "nkids = %d too large, max = %d\n", nkids, NR_THREADS);
			usage(argv[0]);
		}
	}
	printf("%d ", nkids);

	goflag = -1;
	for (i = 0; i < nkids; i++)
		create_thread(counter_test, NULL);

	goflag = 1;
	sleep(1);
	goflag = 0;

	wait_all_threads();

	for_each_thread(i)
		sum += per_thread(counter, i);
	printf("count: %Ld\n", sum);

	exit(0);
}
