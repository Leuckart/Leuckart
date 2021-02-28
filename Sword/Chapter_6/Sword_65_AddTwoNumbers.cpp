/**************************************************
	> File Name:  Sword_65_AddTwoNumbers.cpp
	> Author:     Leuckart
	> Time:       2020-02-28 03:29
**************************************************/

// 面试题65：不用加减乘除做加法
// 题目：写一个函数，求两个整数之和，要求在函数体内不得使用＋、－、×、÷
// 四则运算符号。

#include <cassert>

int Add(int x, int y)
{
	int sum;
	int ext;

	do
	{
		sum = x ^ y;
		ext = (x & y) << 1;

		x = sum;
		y = ext;
	} while (ext != 0);

	return sum;
}

int main(int argc, char *argv[])
{
	assert(Add(1, 2) == 3);
	assert(Add(111, 899) == 1010);

	assert(Add(-1, 2) == 1);
	assert(Add(1, -2) == -1);

	assert(Add(3, 0) == 3);
	assert(Add(0, -4) == -1);

	assert(Add(-2, -8) == -10);

	return 0;
}
