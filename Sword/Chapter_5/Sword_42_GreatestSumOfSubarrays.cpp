/**************************************************
	> File Name:  Sword_42_GreatestSumOfSubarrays.cpp
	> Author:     Leuckart
	> Time:       2020-02-25 23:52
**************************************************/

// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
// 数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。

#include <cassert>
#include <vector>
using namespace std;

int FindGreatestSum(const vector<int> vec)
{
	if (vec.empty())
		return 0;

	vector<int> table(vec.size(), 0);
	table[0] = vec[0];
	int max_sum = table[0];

	for (size_t i = 1; i < vec.size(); ++i)
	{
		if (table[i - 1] < 0)
			table[i] = vec[i];
		else
			table[i] = table[i - 1] + vec[i];

		if (table[i] > max_sum)
			max_sum = table[i];
	}
	return max_sum;
}

int main(int argc, char *argv[])
{
	assert(FindGreatestSum({1, -2, 3, 10, -4, 7, 2, -5}) == 18);
	assert(FindGreatestSum({-2, -8, -1, -5, -9}) == -1);
	assert(FindGreatestSum({2, 8, 1, 5, 9}) == 25);
	assert(FindGreatestSum({}) == 0);

	return 0;
}
