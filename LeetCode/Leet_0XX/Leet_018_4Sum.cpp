/**************************************************
	> File Name:  Leet_018_4Sum.cpp
	> Author:     Leuckart
	> Time:       2019-07-01 16:49
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> fourSum(vector<int> &nums, int target)
	{
		if (nums.size() < 4)
			return {};
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;

		for (int i = 0; i < nums.size() - 3; ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
				break;
			if (nums[i] + nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1] < target)
				continue;

			for (int j = i + 1; j < nums.size() - 2; ++j)
			{
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
					break;
				if (nums[i] + nums[j] + nums[nums.size() - 2] + nums[nums.size() - 1] < target)
					continue;

				for (int k = j + 1, l = nums.size() - 1; k < l;)
				{
					int cur_sum = nums[i] + nums[j] + nums[k] + nums[l];
					if (cur_sum < target)
						++k;
					else if (cur_sum > target)
						--l;
					else
					{
						ans.push_back({nums[i], nums[j], nums[k], nums[l]});
						++k;
						--l;
						while (k < l && nums[k] == nums[k - 1])
							++k;
						while (k < l && nums[l] == nums[l + 1])
							--l;
					}
				}
			}
		}
		return ans;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
