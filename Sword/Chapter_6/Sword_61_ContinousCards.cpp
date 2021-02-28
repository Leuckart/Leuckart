/**************************************************
	> File Name:  Sword_61_ContinousCards.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 18:59
**************************************************/

// 面试题61：扑克牌的顺子
// 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。

#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

bool isContinuous(vector<int> nums)
{
	if (nums.empty())
		return false;
	sort(nums.begin(), nums.end());

	int idx = 0;
	while (idx < nums.size() && nums[idx] == 0)
		++idx;

	int numOf0 = idx;
	int gaps = 0;

	for (int i = idx; i < nums.size() - 1; ++i)
	{
		if (nums[i + 1] == nums[i])
			return false;
		gaps += nums[i + 1] - nums[i] - 1;
	}

	return gaps <= numOf0;
}

int main(int argc, char *argv[])
{
	assert(isContinuous({1, 3, 2, 5, 4}) == true);
	assert(isContinuous({1, 3, 2, 6, 4}) == false);
	assert(isContinuous({0, 3, 2, 6, 4}) == true);
	assert(isContinuous({0, 3, 1, 6, 4}) == false);
	assert(isContinuous({1, 3, 0, 5, 0}) == true);

	assert(isContinuous({1, 3, 0, 7, 0}) == false);
	assert(isContinuous({1, 0, 0, 5, 0}) == true);
	assert(isContinuous({1, 0, 0, 7, 0}) == false);
	assert(isContinuous({3, 0, 0, 0, 0}) == true);
	assert(isContinuous({0, 0, 0, 0, 0}) == true);

	assert(isContinuous({1, 0, 0, 1, 0}) == false);
	assert(isContinuous({}) == false);

	return 0;
}
