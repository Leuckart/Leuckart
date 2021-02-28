/**************************************************
	> File Name:  Leet_057_InsertInterval.cpp
	> Author:     Leuckart
	> Time:       2019-07-17 22:10
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
	{
		int lhs = 0;
		int rhs = 0;

		while (lhs < intervals.size() && newInterval[0] >= intervals[lhs][0])
			++lhs;
		while (rhs < intervals.size() && newInterval[1] >= intervals[rhs][1])
			++rhs;

		int new_l = newInterval[0];
		int new_r = newInterval[1];

		if (lhs > 0 && newInterval[0] <= intervals[lhs - 1][1])
		{
			--lhs;
			new_l = intervals[lhs][0];
		}
		if (rhs < intervals.size() && newInterval[1] >= intervals[rhs][0])
		{
			new_r = intervals[rhs][1];
			++rhs;
		}

		intervals.erase(intervals.begin() + lhs, intervals.begin() + rhs);
		intervals.insert(intervals.begin() + lhs, {new_l, new_r});
		return intervals;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
