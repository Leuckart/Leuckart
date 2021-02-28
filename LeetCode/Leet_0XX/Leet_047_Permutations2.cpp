/**************************************************
	> File Name:  Leet_047_Permutations2.cpp
	> Author:     Leuckart
	> Time:       2019-07-15 15:02
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> permuteUnique(vector<int> &nums)
	{
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		permuteRecursive(result, nums, 0);
		return result;
	}

	void permuteRecursive(vector<vector<int>> &result, vector<int> nums, int idx)
	{
		if (idx == nums.size())
		{
			result.push_back(nums);
			return;
		}

		for (int i = idx; i < nums.size(); ++i)
		{
			if (i != idx && nums[i] == nums[idx])
				continue;
			swap(nums[i], nums[idx]);
			permuteRecursive(result, nums, idx + 1);
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
