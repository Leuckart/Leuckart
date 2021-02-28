/**************************************************
	> File Name:  Leet_034_FindFirstAndLastPosition.cpp
	> Author:     Leuckart
	> Time:       2019-07-05 14:35
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> searchRange(const vector<int> &nums, const int target)
	{
		if (nums.empty())
			return {-1, -1};

		int pos = 0;
		for (int i = 0, j = nums.size() - 1; i < j;)
		{
			pos = (i + j) / 2;
			if (nums[pos] < target)
				i = ++pos;
			else if (nums[pos] > target)
				j = --pos;
			else
				break;
		}
		if (pos < 0 || pos >= nums.size() || nums[pos] != target)
			return {-1, -1};

		int lhs = pos;
		while (lhs > 0 && nums[lhs] == nums[lhs - 1])
			--lhs;
		int rhs = pos;
		while (rhs < nums.size() - 1 && nums[rhs] == nums[rhs + 1])
			++rhs;
		return {lhs, rhs};
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
