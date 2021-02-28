/**************************************************
	> File Name:  Leet_152_MaximumProductSubarray.cpp
	> Author:     Leuckart
	> Time:       2020-03-15 18:24
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProduct(const vector<int> &nums)
	{
		if (nums.empty())
			return 0;

		int result = nums[0];
		int cur_max = nums[0];
		int cur_min = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			int _cur_max = max(nums[i], max(nums[i] * cur_max, nums[i] * cur_min));
			int _cur_min = min(nums[i], min(nums[i] * cur_max, nums[i] * cur_min));
			cur_max = _cur_max;
			cur_min = _cur_min;

			result = max(result, cur_max);
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
