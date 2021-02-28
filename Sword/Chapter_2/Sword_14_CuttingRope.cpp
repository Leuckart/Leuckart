/**************************************************
	> File Name:  Sword_14_CuttingRope.cpp
	> Author:     Leuckart
	> Time:       2020-02-17 01:47
**************************************************/

// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

// ====================动态规划====================
int cuttingRope_solution1(int length)
{
	if (length <= 1)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	vector<int> table(length + 1, 0);
	table[1] = 1;
	table[2] = 2;
	table[3] = 3;

	for (size_t len = 4; len <= length; ++len)
	{
		int maxs = 2 * table[len - 2];
		for (size_t i = 3; i <= len / 2; ++i)
		{
			if (table[i] * table[len - i] > maxs)
				maxs = table[i] * table[len - i];
		}
		table[len] = maxs;
	}
	return table[length];
}

// ====================贪婪算法====================
int cuttingRope_solution2(int length)
{
	if (length <= 1)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int ans = 1;
	while (length >= 5)
	{
		ans *= 3;
		length -= 3;
	}

	return length * ans;
}

int main(int agrc, char *argv[])
{
	assert(cuttingRope_solution1(1) == 0);
	assert(cuttingRope_solution1(2) == 1);
	assert(cuttingRope_solution1(3) == 2);
	assert(cuttingRope_solution1(4) == 4);
	assert(cuttingRope_solution1(5) == 6);
	assert(cuttingRope_solution1(6) == 9);
	assert(cuttingRope_solution1(7) == 12);
	assert(cuttingRope_solution1(8) == 18);
	assert(cuttingRope_solution1(9) == 27);
	assert(cuttingRope_solution1(10) == 36);
	assert(cuttingRope_solution1(50) == 86093442);

	assert(cuttingRope_solution2(1) == 0);
	assert(cuttingRope_solution2(2) == 1);
	assert(cuttingRope_solution2(3) == 2);
	assert(cuttingRope_solution2(4) == 4);
	assert(cuttingRope_solution2(5) == 6);
	assert(cuttingRope_solution2(6) == 9);
	assert(cuttingRope_solution2(7) == 12);
	assert(cuttingRope_solution2(8) == 18);
	assert(cuttingRope_solution2(9) == 27);
	assert(cuttingRope_solution2(10) == 36);
	assert(cuttingRope_solution2(50) == 86093442);

	return 0;
}
