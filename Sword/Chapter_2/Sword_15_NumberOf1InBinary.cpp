/**************************************************
	> File Name:  Sword_15_NumberOf1InBinary.cpp
	> Author:     Leuckart
	> Time:       2020-02-17 04:16
**************************************************/

// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

#include <cassert>

int numberOf1(int num)
{
	int count = 0;
	while (num)
	{
		++count;
		num &= (num - 1);
	}
	return count;
}

int main(int argc, char *argv[])
{
	assert(numberOf1(0) == 0);
	assert(numberOf1(1) == 1);
	assert(numberOf1(10) == 2);
	assert(numberOf1(0x7FFFFFFF) == 31);
	assert(numberOf1(0xFFFFFFFF) == 32);
	assert(numberOf1(0x80000000) == 1);

	return 0;
}
