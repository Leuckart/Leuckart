/**************************************************
	> File Name:  Sword_51_InversePairs.cpp
	> Author:     Leuckart
	> Time:       2020-02-26 20:05
**************************************************/

// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
// 成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int InversePairsRecursive(vector<int> &data, vector<int> &copy, int beg, int end)
{
	if (beg == end)
	{
		copy[beg] = data[beg];
		return 0;
	}

	int mid = (beg + end) / 2;
	int count_lhs = InversePairsRecursive(copy, data, beg, mid);
	int count_rhs = InversePairsRecursive(copy, data, mid + 1, end);
	int count_cur = count_lhs + count_rhs;

	// lhs 初始化为前半段最后一个数字的下标
	int lhs = mid;
	// rhs 初始化为后半段最后一个数字的下标
	int rhs = end;
	// rhs 初始化为copy中最后一个数字的下标
	int pos = end;

	while (lhs >= beg && rhs > mid)
	{
		if (data[lhs] <= data[rhs])
			copy[pos--] = data[rhs--];
		else
		{
			copy[pos--] = data[lhs--];
			count_cur += rhs - mid;
		}
	}

	while (lhs >= beg)
		copy[pos--] = data[lhs--];
	while (rhs > mid)
		copy[pos--] = data[rhs--];

	return count_cur;
}

int InversePairs(vector<int> data)
{
	if (data.empty())
		return 0;

	vector<int> copy = data;
	return InversePairsRecursive(data, copy, 0, data.size() - 1);
}

int main(int argc, char *argv[])
{
	assert(InversePairs({1, 2, 3, 4, 7, 6, 5}) == 3);
	assert(InversePairs({6, 5, 4, 3, 2, 1}) == 15);
	assert(InversePairs({1, 2, 3, 4, 5, 6}) == 0);
	assert(InversePairs({1, 2}) == 0);
	assert(InversePairs({2, 1}) == 1);
	assert(InversePairs({1, 2, 1, 2, 1}) == 3);
	assert(InversePairs({1}) == 0);
	assert(InversePairs({}) == 0);

	return 0;
}
