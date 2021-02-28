/**************************************************
	> File Name:  Sword_56_2_NumberAppearingOnce.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 05:07
**************************************************/

// 面试题56（二）：数组中唯一只出现一次的数字
// 题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请
// 找出那个吃出现一次的数字。

#include <cassert>
#include <vector>
using namespace std;

int FindNumberAppearOnce(const vector<int> &nums)
{
	if (nums.empty())
		return -1;

	vector<int> bits(32, 0);
	for (size_t idx = 0; idx < nums.size(); ++idx)
		for (size_t j = 0; j < 32; ++j)
			bits[j] += (nums[idx] & (1 << j)) != 0;

	int result = 0;
	for (size_t i = 0; i < 32; ++i)
		if (bits[i] % 3)
			result |= 1 << i;

	return result;
}

int main(int argc, char *argv[])
{
	assert(FindNumberAppearOnce({1, 1, 2, 2, 2, 1, 3}) == 3);
	assert(FindNumberAppearOnce({4, 3, 3, 2, 2, 2, 3}) == 4);
	assert(FindNumberAppearOnce({4, 4, 1, 1, 1, 7, 4}) == 7);
	assert(FindNumberAppearOnce({-10, 214, 214, 214}) == -10);
	assert(FindNumberAppearOnce({-209, 3467, -209, -209}) == 3467);
	assert(FindNumberAppearOnce({1024, -1025, 1024, -1025, 1024, -1025, 1023}) == 1023);
	assert(FindNumberAppearOnce({-1024, -1024, -1024, -1023}) == -1023);
	assert(FindNumberAppearOnce({-23, 0, 214, -23, 214, -23, 214}) == 0);
	assert(FindNumberAppearOnce({0, 3467, 0, 0, 0, 0, 0, 0}) == 3467);

	return 0;
}
