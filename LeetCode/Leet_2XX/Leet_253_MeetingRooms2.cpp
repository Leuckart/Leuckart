/**************************************************
	> File Name:  Leet_253_MeetingRooms2.cpp
	> Author:     Leuckart
	> Time:       2020-04-01 13:12
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	int minMeetingRooms(vector<vector<int>> &intervals)
	{
		sort(intervals.begin(), intervals.end(),
			 [](const vector<int> &v1, const vector<int> &v2) { return v1[0] < v2[0]; });

		int cur_max = 0;
		priority_queue<int, vector<int>, greater<int>> PQ;
		for (int i = 0; i < intervals.size(); ++i)
		{
			while (!PQ.empty() && PQ.top() <= intervals[i][0])
				PQ.pop();
			PQ.push(intervals[i][1]);
			cur_max = max(cur_max, int(PQ.size()));
		}
		return cur_max;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
