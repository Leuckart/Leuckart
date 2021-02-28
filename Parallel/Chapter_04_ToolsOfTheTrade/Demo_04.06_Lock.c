/**************************************************
	> File Name:  Demo_04.06_Lock.c
	> Author:     Leuckart
	> Time:       2019-12-15 01:03
**************************************************/

/* Lock.c */
/* 展示 POSIX 中 pthread_mutex_lock() 与 pthread_mutex_unlock() 原语的使用 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

#include <poll.h>
#include <string.h>
#include "Tools.h"

// pthread_mutex_t 锁的静态声明和初始化由 PTHREAD_MUTEX_INITIALIZER 完成，或由 pthread_mutex_init() 原语进行动态分配和初始化
// pthread_mutex_lock() 原语获取指定锁
// pthread_mutex_unlock() 原语释放指定锁

pthread_mutex_t lock_a = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_b = PTHREAD_MUTEX_INITIALIZER;

int x = 0;

void *lock_reader(void *arg)
{
	int en;
	int newx = -1;
	int oldx = -1;
	pthread_mutex_t *pmlp = (pthread_mutex_t *)arg;

	if ((en = pthread_mutex_lock(pmlp)) != 0)
	{
		fprintf(stderr, "lock_reader:pthread_mutex_lock: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 100; ++i)
	{
		newx = READ_ONCE(x);
		if (newx != oldx)
		{
			printf("lock_reader(): x = %d\n", newx);
		}
		oldx = newx;
		poll(NULL, 0, 1);
	}
	if ((en = pthread_mutex_unlock(pmlp)) != 0)
	{
		fprintf(stderr, "lock_reader:pthread_mutex_lock: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}
	return NULL;
}

void *lock_writer(void *arg)
{
	int en;
	pthread_mutex_t *pmlp = (pthread_mutex_t *)arg;

	if ((en = pthread_mutex_lock(pmlp)) != 0)
	{
		fprintf(stderr, "lock_writer:pthread_mutex_lock: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 3; ++i)
	{
		WRITE_ONCE(x, READ_ONCE(x) + 1);
		poll(NULL, 0, 5);
	}
	if ((en = pthread_mutex_unlock(pmlp)) != 0)
	{
		fprintf(stderr, "lock_writer:pthread_mutex_lock: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	int en;
	pthread_t tid1;
	pthread_t tid2;
	void *vp;

	printf("Creating two threads using same lock:\n");
	if ((en = pthread_create(&tid1, NULL, lock_reader, &lock_a)) != 0)
	{
		fprintf(stderr, "pthread_create: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}
	if ((en = pthread_create(&tid2, NULL, lock_writer, &lock_a)) != 0)
	{
		fprintf(stderr, "pthread_create: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}

	if ((en = pthread_join(tid1, &vp)) != 0)
	{
		fprintf(stderr, "pthread_join: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}
	if ((en = pthread_join(tid2, &vp)) != 0)
	{
		fprintf(stderr, "pthread_join: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}

	printf("Creating two threads w/different locks:\n");
	x = 0;
	if ((en = pthread_create(&tid1, NULL, lock_reader, &lock_a)) != 0)
	{
		fprintf(stderr, "pthread_create: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}
	if ((en = pthread_create(&tid2, NULL, lock_writer, &lock_b)) != 0)
	{
		fprintf(stderr, "pthread_create: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}

	if ((en = pthread_join(tid1, &vp)) != 0)
	{
		fprintf(stderr, "pthread_join: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}
	if ((en = pthread_join(tid2, &vp)) != 0)
	{
		fprintf(stderr, "pthread_join: %s\n", strerror(en));
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
