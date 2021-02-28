/**************************************************
	> File Name:  Sword_53_3_IntegerIdenticalToIndex.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 02:39
**************************************************/

// 面试题53（三）：数组中数值和下标相等的元素
// 题目：假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实
// 现一个函数找出数组中任意一个数值等于其下标的元素。例如，在数组{-3, -1,
// 1, 3, 5}中，数字3和它的下标相等。

#include <cassert>
#include <vector>
using namespace std;

int GetNumberSameAsIndex(const vector<int> &nums)
{
	if (nums.empty())
		return -1;

	for (int lhs = 0, rhs = nums.size() - 1; lhs <= rhs;)
	{
		int mid = (lhs + rhs) / 2;

		if (nums[mid] < mid)
			lhs = mid + 1;
		else if (nums[mid] > mid)
			rhs = mid - 1;
		else
			return mid;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	assert(GetNumberSameAsIndex({-3, -1, 1, 3, 5}) == 3);
	assert(GetNumberSameAsIndex({0, 1, 3, 5, 6}) == 0);
	assert(GetNumberSameAsIndex({-1, 0, 1, 2, 4}) == 4);
	assert(GetNumberSameAsIndex({-1, 0, 1, 2, 5}) == -1);
	assert(GetNumberSameAsIndex({0}) == 0);
	assert(GetNumberSameAsIndex({10}) == -1);
	assert(GetNumberSameAsIndex({}) == -1);

	return 0;
}
