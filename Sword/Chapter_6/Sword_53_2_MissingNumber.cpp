/**************************************************
	> File Name:  Sword_53_2_MissingNumber.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 02:11
**************************************************/

// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
// 都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
// 中，请找出这个数字。

#include <cassert>
#include <vector>
using namespace std;

int GetMissingNumber(const vector<int> &nums)
{
	if (nums.empty())
		return -1;

	for (int lhs = 0, rhs = nums.size() - 1; lhs <= rhs;)
	{
		int mid = (lhs + rhs) / 2;

		if (nums[mid] == mid)
			lhs = mid + 1;
		else if (mid == 0 || nums[mid - 1] == mid - 1)
			return mid;
		else
			rhs = mid - 1;
	}

	if (nums[nums.size() - 1] == nums.size() - 1)
		return nums.size();
	else
		return -1;
}

int main(int argc, char *argv[])
{
	assert(GetMissingNumber({1, 2, 3, 4, 5}) == 0);
	assert(GetMissingNumber({0, 1, 2, 3, 4}) == 5);
	assert(GetMissingNumber({0, 1, 2, 4, 5}) == 3);
	assert(GetMissingNumber({1}) == 0);
	assert(GetMissingNumber({0}) == 1);

	return 0;
}
