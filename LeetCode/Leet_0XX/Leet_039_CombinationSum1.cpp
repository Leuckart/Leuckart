/**************************************************
	> File Name:  Leet_039_CombinationSum1.cpp
	> Author:     Leuckart
	> Time:       2019-07-08 16:43
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int> &candidates, const int target)
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

		for (int i = idx; i < candidates.size() && candidates[i] <= target; ++i)
		{
			path.push_back(candidates[i]);
			combinationSumCore(ans, path, candidates, i, target - candidates[i]);
			path.pop_back();
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
