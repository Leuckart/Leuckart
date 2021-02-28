/**************************************************
	> File Name:  Demo_04.05_PCreate.c
	> Author:     Leuckart
	> Time:       2019-12-15 01:12
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

/* PCreate.c: Demonstrate use of POSIX pthread_create() and pthread_join() primitives for parallel processing. */

int x = 0;

void *mythread(void *arg)
{
	x = 1;
	printf("Child process set x=1\n");
	return NULL;
}

// 在一个已有的进程中创建线程，需要调用 pthread_create() 原语。
// 第一个参数是指向 pthread_t 的指针，用于存放将要创建的线程的ID。
// 第二个参数可选，指向 pthread_attr_t 结构。
// 第三个参数是新线程将要调用的函数。
// 第四个参数可选，指向传递给以上函数的参数。
int main(int argc, char *argv[])
{
	int en;
	pthread_t tid;
	void *vp;

	if ((en = pthread_create(&tid, NULL, mythread, NULL)) != 0)
	{
		fprintf(stderr, "pthread_join: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}

	/* parent */
	// pthread_join 原语阻塞直到 tid 指定的线程返回。
	if ((en = pthread_join(tid, &vp)) != 0)
	{
		fprintf(stderr, "pthread_join: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}
	printf("Parent process sees x=%d\n", x);

	return EXIT_SUCCESS;
}
