
# 深入理解并行编程

## 第二章 简介

## 第四章 工具

[Parallel_04.01_Parallel.sh](./Chapter_04_ToolsOfTheTrade/Parallel_04.01_Parallel.sh)

[Parallel_04.02_ForkJoin.c](./Chapter_04_ToolsOfTheTrade/Parallel_04.02_ForkJoin.c)
// 进程通过 fork() 原语创建，使用 kill() 原语销毁，也可以用 exit() 原语自我撤销。
// 父进程可通过 wait() 原语等待子进程执行完毕。

[Parallel_04.04_ForkJoinVar.c](./Chapter_04_ToolsOfTheTrade/Parallel_04.04_ForkJoinVar.c)

### 返回参数原值的原子操作：

__sync_fetch_and_add()

__sync_fetch_and_sub()

__sync_fetch_and_or()

__sync_fetch_and_and()

__sync_fetch_and_xor()

__sync_fetch_and_nand()

### 返回参数新值的原子操作：

__sync_add_and_fetch()

__sync_sub_and_fetch()

__sync_or_and_fetch()

__sync_and_and_fetch()

__sync_xor_and_fetch()

__sync_nand_and_fetch()

### 比较并交换（CAS）原语

__sync_bool_compare_and_swap()

__sync_val_compare_and_swap()

### 内存屏障原语

__sync_synchronize() 限制编译器和CPU对指令乱序执行的优化

barrier() 限制编译器对指令乱序执行的优化，而不限制CPU的优化

#define barrier() __asm__ __volatile__("": : :"memory")

ACCESS_ONCE() 限制编译器对某个内存访问的优化

#define ACCESS_ONCE(x) (*(volatile typeof(x) *) &(x))

## 第五章 计数

