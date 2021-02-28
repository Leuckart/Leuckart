/**************************************************
	> File Name:  Demo_04.03_ForkJoinVar.c
	> Author:     Leuckart
	> Time:       2019-12-15 00:57
**************************************************/

/* ForkJoinVar.c */
/* 展示在并行编程中 POSIX fork() 与 wait() 原语的使用方式，以及父进程与子进程间不共享内存 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <poll.h>
#include <unistd.h>
#include "Tools.h"

int x = 0;

int main(int argc, char *argv[])
{
	int pid = fork();

	if (pid == 0)
	{
		x = 1;
		printf("Child process set x=1\n");
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
	{
		/* parent, upon error */
		perror("fork");
		exit(EXIT_FAILURE);
	}

	/* parent */
	my_waitall();
	printf("Parent process sees x=%d\n", x);

	return EXIT_SUCCESS;
}
