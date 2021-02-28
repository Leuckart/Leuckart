/**************************************************
	> File Name:  Leet_056_MergeIntervals.cpp
	> Author:     Leuckart
	> Time:       2019-07-18 13:15
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals)
	{
		sort(intervals.begin(), intervals.end(), [](const vector<int> &x, const vector<int> &y) { return x[0] < y[0]; });
		vector<vector<int>> result;

		for (int i = 0; i < intervals.size();)
		{
			result.push_back(intervals[i]);

			while (i < intervals.size() && intervals[i][0] <= result.back()[1])
			{
				result.back()[1] = max(result.back()[1], intervals[i][1]);
				++i;
			}
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
