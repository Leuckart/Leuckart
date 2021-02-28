/**************************************************
	> File Name:  Sword_59_1_MaxInSlidingWindow.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 14:57
**************************************************/

// 面试题59（一）：滑动窗口的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，

#include <iostream>
#include <cassert>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxWindow(const vector<int> &nums, int size)
{
	if (nums.size() < size || size == 0)
		return {};

	vector<int> result(nums.size() - size + 1, 0);
	deque<int> index;

	for (size_t idx = 0; idx < size; ++idx)
	{
		while (!index.empty() && nums[idx] >= nums[index.back()])
			index.pop_back();
		index.push_back(idx);
	}
	result[0] = nums[index.front()];

	for (size_t idx = size; idx < nums.size(); ++idx)
	{
		if (index.front() <= idx - size)
			index.pop_front();

		while (!index.empty() && nums[idx] >= nums[index.back()])
			index.pop_back();
		index.push_back(idx);

		result[idx - size + 1] = nums[index.front()];
	}
	return result;
}

bool beSame(const vector<int> &vec1, const vector<int> &vec2)
{
	if (vec1.size() != vec2.size())
		return false;

	for (size_t i = 0; i < vec1.size(); ++i)
		if (vec1[i] != vec2[i])
			return false;
	return true;
}

int main(int argc, char *argv[])
{
	assert(beSame(maxWindow({2, 3, 4, 2, 6, 2, 5, 1}, 3), {4, 4, 6, 6, 6, 5}));
	assert(beSame(maxWindow({1, 3, -1, -3, 5, 3, 6, 7}, 3), {3, 3, 5, 5, 6, 7}));
	assert(beSame(maxWindow({1, 3, 5, 7, 9, 11, 13, 15}, 4), {7, 9, 11, 13, 15}));
	assert(beSame(maxWindow({16, 14, 12, 10, 8, 6, 4}, 5), {16, 14, 12}));
	assert(beSame(maxWindow({10, 14, 12, 11}, 1), {10, 14, 12, 11}));
	assert(beSame(maxWindow({10, 14, 12, 11}, 4), {14}));
	assert(beSame(maxWindow({10, 14, 12, 11}, 0), {}));
	assert(beSame(maxWindow({10, 14, 12, 11}, 5), {}));
	assert(beSame(maxWindow({}, 5), {}));

	return 0;
}
