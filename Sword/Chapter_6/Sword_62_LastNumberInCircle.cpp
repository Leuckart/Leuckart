/**************************************************
	> File Name:  Sword_62_LastNumberInCircle.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 20:52
**************************************************/

// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
// 删除第m个数字。求出这个圆圈里剩下的最后一个数字。

#include <cassert>
using namespace std;

int LastRemaining(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
		return -1;

	int last = 0;
	for (int i = 2; i <= n; ++i)
		last = (last + m) % i;

	return last;
}

int main(int argc, char *argv[])
{
	assert(LastRemaining(5, 3) == 3);
	assert(LastRemaining(5, 2) == 2);
	assert(LastRemaining(6, 7) == 4);
	assert(LastRemaining(6, 6) == 3);
	assert(LastRemaining(4000, 997) == 1027);

	return 0;
}
