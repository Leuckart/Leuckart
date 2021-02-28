/**************************************************
	> File Name:  Leet_040_CombinationSum2.cpp
	> Author:     Leuckart
	> Time:       2019-07-08 18:20
**************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
	{
		vector<vector<int>> ans;
		sort(candidates.begin(), candidates.end());
		combinationSumCore(ans, {}, candidates, 0, target);
		return ans;
	}

private:
	void combinationSumCore(vector<vector<int>> &ans, vector<int> path, const vector<int> &candidates,
							const int idx, const int target)
	{
		if (target == 0)
		{
			ans.push_back(path);
			return;
		}

		for (int i = idx; i < candidates.size() && candidates[i] <= target;)
		{
			path.push_back(candidates[i]);
			combinationSumCore(ans, path, candidates, i + 1, target - candidates[i]);
			path.pop_back();

			// 越过重复的数字
			do
			{
				++i;
			} while (i < candidates.size() && candidates[i] == candidates[i - 1]);
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
