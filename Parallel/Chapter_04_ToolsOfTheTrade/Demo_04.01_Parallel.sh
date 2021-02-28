############################################################
# File Name:  Demo_04.01_Parallel.sh
# Author:  Leuckart
# Time:    2019-12-15   01:11
############################################################
#!/bin/bash

# Parallel.sh: Example parallel and pipelined shell script. #

function compute_it
{
	echo computing $1
	sleep 5
}

# Parallel
# & ：指定程序在后台运行。
echo Computing in parallel starting at `date`
compute_it 1 > compute_it.1.out &
compute_it 2 > compute_it.2.out &
wait
echo Computing in parallel finished at `date`
echo Computation \"output\":
cat compute_it.1.out
cat compute_it.2.out
rm compute_it.1.out compute_it.2.out

# Sequentially
echo
echo Computing sequentially starting at `date`
compute_it 1 > compute_it.1.out
compute_it 2 > compute_it.2.out
echo Computing sequentially finished at `date`
echo Computation \"output\":
cat compute_it.1.out
cat compute_it.2.out
rm compute_it.1.out compute_it.2.out

# Pipeline
# 管道触发两个子进程执行"|"两边的程序；而重定向是在一个进程内执行
# | ：左边的命令应该有正确的标准输出（不处理错误输出），右边的命令应该接受标准输入。
# > ：左边的命令应该有标准输出，右边只能是文件（如标准空文件/dev/null）。
# < ：左边的命令应该需要标准输入，右边只能是文件 。
echo
echo Computing in pipeline starting at `date`
compute_it 1 | compute_it 2 > compute_it.out
echo Computing in pipeline finished at `date`
echo Computation \"output\":
cat compute_it.out
rm compute_it.out
