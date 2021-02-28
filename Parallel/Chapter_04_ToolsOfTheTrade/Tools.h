/**************************************************
	> File Name:  tools.h
	> Author:     Leuckart
	> Time:       2019-12-17 10:01
**************************************************/

#ifndef TOOLS_H_
#define TOOLS_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

#include <poll.h>
#include <unistd.h>

#define ACCESS_ONCE(x) (*(volatile typeof(x) *)&(x))

#define READ_ONCE(x) \
	({ typeof(x) ___x = ACCESS_ONCE(x); ___x; })

#define WRITE_ONCE(x, val)      \
	do                          \
	{                           \
		ACCESS_ONCE(x) = (val); \
	} while (0)

#define barrier() __asm__ __volatile__("" \
									   :  \
									   :  \
									   : "memory")

/* Wait on all child processes. */
/* 父进程执行了wait函数后，如果子进程已经发生了状态变化，则wait函数立即就会有返回结果； */
/* 否则wait函数会一直阻塞直至子进程状态发生变化。 */
static __inline__ void my_waitall(void)
{
	int pid;
	int status;

	while (1)
	{
		pid = wait(&status);
		/* 当进入以下 if 块时，表示 wait() 无法再等待子进程执行完毕 */
		/* 检查错误码 errno 是否为 ECHILD，若是则表示无其他子进程 */
		// printf("%d\n", pid);
		if (pid == -1)
		{
			if (errno == ECHILD)
				break;
			perror("wait");
			exit(EXIT_FAILURE);
		}
		poll(NULL, 0, 1);
	}
}

#endif
