/**************************************************
	> File Name:  Leet_015_3Sum.cpp
	> Author:     Leuckart
	> Time:       2019-06-27 23:54
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); ++i)
		{
			int target = -nums[i];
			if (target < 0)
				break;

			for (int left = i + 1, right = nums.size() - 1; left < right;)
			{
				int cur_sum = nums[left] + nums[right];
				if (cur_sum == target)
				{
					ans.push_back({nums[i], nums[left], nums[right]});
					while (left < right && nums[left] == ans.back()[1])
						++left;
					while (left < right && nums[right] == ans.back()[2])
						--right;
				}
				else if (cur_sum < target)
					++left;
				else
					--right;
			}
			while (i < nums.size() - 1 && nums[i] == nums[i + 1])
				++i;
		}
		return ans;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
