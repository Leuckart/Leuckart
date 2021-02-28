/**************************************************
	> File Name:  Demo_04.04_ForkJoinPerf.c
	> Author:     Leuckart
	> Time:       2019-12-15 00:55
**************************************************/

/* ForkJoinPerf.c */
/* 衡量 fork() 调用的时间开销 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int status;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s nforks\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	const int nforks = atoi(argv[1]);
	printf("%d fork()s\n", nforks);
	printf("Starting at ");
	fflush(stdout);

	int i = system("date");
	for (i = 0; i < nforks; ++i)
	{
		int pid = fork();
		if (pid == 0)
		{
			/* child */
			exit(EXIT_SUCCESS);
		}
		else if (pid < 0)
		{
			/* parent, upon error */
			perror("fork");
			exit(EXIT_FAILURE);
		}

		/* 需要进入以下循环多次，最后一次 wait() 返回的 pid 为 -1 */
		while (1)
		{
			pid = wait(&status);
			if (pid == -1)
			{
				if (errno == ECHILD)
					break;
				perror("wait");
				exit(EXIT_FAILURE);
			}
		}
	}
	printf("Finished at ");
	fflush(stdout);
	i = system("date");

	return EXIT_SUCCESS;
}
