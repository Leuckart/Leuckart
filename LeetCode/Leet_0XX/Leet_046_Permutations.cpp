/**************************************************
	> File Name:  Leet_046_Permutations.cpp
	> Author:     Leuckart
	> Time:       2019-07-15 10:35
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<vector<int>> result;
		permuteCore(result, nums, 0);
		return result;
	}

private:
	void permuteCore(vector<vector<int>> &result, vector<int> &nums, int idx)
	{
		if (idx == nums.size())
		{
			result.push_back(nums);
			return;
		}

		for (int i = idx; i < nums.size(); ++i)
		{
			swap(nums[idx], nums[i]);
			permuteCore(result, nums, idx + 1);
			swap(nums[idx], nums[i]);
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
