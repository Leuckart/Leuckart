/**************************************************
	> File Name:  Demo_02.06_ThreadCreate.c
	> Author:     Leuckart
	> Time:       2019-12-19 16:04
**************************************************/

/* ThreadCreate.c: simple program demonstrating thread primitives. */

#include "Tools.h"

void *thread_test(void *arg)
{
	int myarg = (intptr_t)arg;

	printf("child thread %d: smp_thread_id() = %d\n",
		   myarg, smp_thread_id());
	return NULL; //\lnlbl{return}
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
	}													   //\lnlbl{parse:e}
	printf("Parent thread spawning %d threads.\n", nkids); //\lnlbl{announce}

	for (i = 0; i < nkids; i++)							 //\lnlbl{create:b}
		create_thread(thread_test, (void *)(intptr_t)i); //\lnlbl{create:e}

	wait_all_threads(); //\lnlbl{wait}

	printf("All spawned threads completed.\n");

	exit(0);
}
//\end{snippet}
