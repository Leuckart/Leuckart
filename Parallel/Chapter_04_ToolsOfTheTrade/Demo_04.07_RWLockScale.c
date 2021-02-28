/**************************************************
	> File Name:  Demo_04.07_RWLockScale.c
	> Author:     Leuckart
	> Time:       2019-12-15 01:15
**************************************************/

/* rwlockscale.c */
/* 展示 POSIX 中 pthread_rwlock_rdlock() 和 pthread_rwlock_unlock() 的使用  */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "Tools.h"

// pthread_rwlock_init() 锁可由 PTHREAD_RWLOCK_INITIALIZER 静态初始化，或由 pthread_rwlock_init() 原语动态初始化
// pthread_rwlock_rdlock() 原语获取 pthread_rwlock_t 写锁
// pthread_rwlock_wrlock() 原语获取 pthread_rwlock_t 读锁
// pthread_rwlock_unlock() 原语释放 pthread_rwlock_t 锁
// 任意时刻只能有一个线程持有给定 pthread_rwlock_t 写锁，但可有多个线程持有 pthread_rwlock_t 读锁，至少在无线程持有写锁时是如此

pthread_rwlock_t rwl = PTHREAD_RWLOCK_INITIALIZER;

int holdtime = 0;		 // 控制每个线程持有读写锁的时间
int thinktime = 0;		 // 控制每个线程释放读写锁与下一次获取读写锁之间的间隔时间
long long *readcounts;	 // 存放每个读线程获取锁的次数
int nreadersrunning = 0; // 控制所有读线程何时开始执行

#define GOFLAG_INIT 0
#define GOFLAG_RUN 1
#define GOFLAG_STOP 2
char goflag = GOFLAG_INIT;

void *reader(void *arg)
{
	int en;
	long long loopcnt = 0;
	long me = (long)arg;

	__sync_fetch_and_add(&nreadersrunning, 1);
	while (READ_ONCE(goflag) == GOFLAG_INIT)
		continue;

	while (READ_ONCE(goflag) == GOFLAG_RUN)
	{
		if ((en = pthread_rwlock_rdlock(&rwl)) != 0)
		{
			fprintf(stderr, "pthread_rwlock_rdlock: %s\n", strerror(en));
			exit(EXIT_FAILURE);
		}
		for (int i = 1; i < holdtime; ++i)
			barrier();

		if ((en = pthread_rwlock_unlock(&rwl)) != 0)
		{
			fprintf(stderr, "pthread_rwlock_unlock: %s\n", strerror(en));
			exit(EXIT_FAILURE);
		}
		for (int i = 1; i < thinktime; ++i)
			barrier();

		loopcnt++; // 统计锁的获取次数
	}
	readcounts[me] = loopcnt;
	return NULL;
}

int main(int argc, char *argv[])
{
	int en;
	void *vp;

	if (argc != 4)
	{
		fprintf(stderr, "Usage: %s nthreads holdloops thinkloops\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int nthreads = strtoul(argv[1], NULL, 0);
	holdtime = strtoul(argv[2], NULL, 0);
	thinktime = strtoul(argv[3], NULL, 0);

	readcounts = malloc(nthreads * sizeof(readcounts[0]));
	pthread_t *tid = malloc(nthreads * sizeof(tid[0]));
	if (readcounts == NULL || tid == NULL)
	{
		fprintf(stderr, "Out of memory\n");
		exit(EXIT_FAILURE);
	}

	for (long i = 0; i < nthreads; ++i)
	{
		if ((en = pthread_create(&tid[i], NULL, reader, (void *)i)) != 0)
		{
			fprintf(stderr, "pthread_create: %s\n", strerror(en));
			exit(EXIT_FAILURE);
		}
	}
	while (READ_ONCE(nreadersrunning) < nthreads)
		continue;

	goflag = GOFLAG_RUN;
	sleep(1);
	goflag = GOFLAG_STOP;

	for (int i = 0; i < nthreads; ++i)
	{
		if ((en = pthread_join(tid[i], &vp)) != 0)
		{
			fprintf(stderr, "pthread_join: %s\n", strerror(en));
			exit(EXIT_FAILURE);
		}
	}

	long long sum = 0LL;
	for (long i = 0; i < nthreads; ++i)
		sum += readcounts[i];
	printf("%s n: %d  h: %d t: %d  sum: %lld\n",
		   argv[0], nthreads, holdtime, thinktime, sum);

	return EXIT_SUCCESS;
}
