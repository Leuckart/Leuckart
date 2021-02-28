/**************************************************
	> File Name:  Leet_016_3SumClosest.cpp
	> Author:     Leuckart
	> Time:       2019-07-01 13:50
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int> &nums, int target)
	{
		if (nums.size() < 3)
			return 0;
		sort(nums.begin(), nums.end());
		int min_diff = nums[0] + nums[1] + nums[2] - target;

		for (int i = 0; i < nums.size() - 2; ++i)
		{
			for (int lhs = i + 1, rhs = nums.size() - 1; lhs < rhs;)
			{
				int cur_diff = nums[i] + nums[lhs] + nums[rhs] - target;
				if (abs(cur_diff) < abs(min_diff))
					min_diff = cur_diff;
				if (cur_diff < 0)
					++lhs;
				else if (cur_diff > 0)
					--rhs;
				else
					return target;
			}
		}
		return target + min_diff;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
