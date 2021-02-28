/**************************************************
	> File Name:  Leet_090_Subsets2.cpp
	> Author:     Leuckart
	> Time:       2019-07-26 22:25
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums)
	{
		vector<int> item;
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		subsetsWithDupCore(result, item, nums, 0);
		return result;
	}

private:
	void subsetsWithDupCore(vector<vector<int>> &result, vector<int> &item, const vector<int> &nums, int idx)
	{
		result.push_back(item);
		for (int i = idx; i < nums.size(); ++i)
		{
			// 跳过重复元素
			if (i > idx && nums[i] == nums[i - 1])
				continue;

			item.push_back(nums[i]);
			subsetsWithDupCore(result, item, nums, i + 1);
			item.pop_back();
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
