/**************************************************
	> File Name:  Demo_02.04_NakedInc.c
	> Author:     Leuckart
	> Time:       2019-12-19 16:00
**************************************************/

/* NakedInc.c: simple program demonstrating simple increment performance. */

#include "Tools.h"

int counter = 0;
int goflag;

void initcounter(void)
{
}

void *counter_test(void *arg)
{
	while (goflag < 0)
		continue;
	while (goflag)
	{
		counter++;
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
	for (i = 0; i < nkids; i++)
		create_thread(counter_test, NULL);

	goflag = 1;
	sleep(1);
	goflag = 0;

	wait_all_threads();

	printf("count: %d\n", counter);

	exit(0);
}
