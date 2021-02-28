/**************************************************
	> File Name:  Demo_04.02_ForkJoin.c
	> Author:     Leuckart
	> Time:       2019-12-15 00:50
**************************************************/

/* ForkJoin.c */
/* 展示在并行编程中 POSIX fork() 与 wait() 原语的使用方式 */

#include "Tools.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s nforks. \tBy Leuckart.\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	const int nforks = atoi(argv[1]);
	printf("%d fork()s\n", nforks);
	printf("Starting at ");
	fflush(stdout);

	int stat_val = system("date");
	if (!WIFEXITED(stat_val) || WEXITSTATUS(stat_val))
	{
		fprintf(stderr, "system(\"date\") failed: %x. \tBy Leuckart.\n", stat_val);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < nforks; ++i)
	{
		pid_t pid = fork();
		if (pid == 0)
		{
			/* child */
			sleep(1);
			exit(0);
		}
		else if (pid < 0)
		{
			/* parent, upon error */
			perror("fork");
			exit(EXIT_FAILURE);
		}
	}

	/* parent */
	my_waitall();
	printf("Finished at ");
	fflush(stdout);

	stat_val = system("date");
	if (!WIFEXITED(stat_val) || WEXITSTATUS(stat_val))
	{
		fprintf(stderr, "system(\"date\") failed: %x\n", stat_val);
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
