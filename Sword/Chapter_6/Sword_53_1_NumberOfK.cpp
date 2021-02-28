/**************************************************
	> File Name:  Sword_53_1_NumberOfK.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 01:15
**************************************************/

// 面试题53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
// 3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。

#include <cassert>
#include <vector>
using namespace std;

int GetFisrtK(const vector<int> &data, int targ, int lhs, int rhs)
{
	if (lhs > rhs)
		return -1;

	int mid = (lhs + rhs) / 2;
	if (data[mid] < targ)
		return GetFisrtK(data, targ, mid + 1, rhs);
	else if (data[mid] > targ)
		return GetFisrtK(data, targ, lhs, mid - 1);
	else if (mid == 0 || data[mid - 1] != targ)
		return mid;
	else
		return GetFisrtK(data, targ, lhs, mid - 1);
}

int GetLastK(const vector<int> &data, int targ, int lhs, int rhs)
{
	if (lhs > rhs)
		return -2;

	int mid = (lhs + rhs) / 2;
	if (data[mid] < targ)
		return GetLastK(data, targ, mid + 1, rhs);
	else if (data[mid] > targ)
		return GetLastK(data, targ, lhs, mid - 1);
	else if (mid == data.size() - 1 || data[mid + 1] != targ)
		return mid;
	else
		return GetLastK(data, targ, mid + 1, rhs);
}

int NumberOfK(const vector<int> &data, int target)
{
	if (data.empty())
		return 0;

	int firstK = GetFisrtK(data, target, 0, data.size() - 1);
	int lastK = GetLastK(data, target, 0, data.size() - 1);

	return lastK - firstK + 1;
}

int main(int argc, char *argv[])
{
	assert(NumberOfK({1, 2, 3, 3, 3, 3, 4, 5}, 3) == 4);
	assert(NumberOfK({3, 3, 3, 3, 4, 5}, 3) == 4);
	assert(NumberOfK({1, 2, 3, 3, 3, 3}, 3) == 4);
	assert(NumberOfK({1, 3, 3, 3, 3, 4, 5}, 2) == 0);
	assert(NumberOfK({1, 3, 3, 3, 3, 4, 5}, 0) == 0);
	assert(NumberOfK({1, 3, 3, 3, 3, 4, 5}, 6) == 0);
	assert(NumberOfK({3, 3, 3, 3}, 3) == 4);
	assert(NumberOfK({3, 3, 3, 3}, 4) == 0);
	assert(NumberOfK({3}, 3) == 1);
	assert(NumberOfK({3}, 4) == 0);
	assert(NumberOfK({}, 0) == 0);

	return 0;
}
