/**************************************************
	> File Name:  Leet_210_CourseSchedule2.cpp
	> Author:     Leuckart
	> Time:       2020-09-22 16:11
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findOrder(const int numCourses, const vector<vector<int>> &prerequisites)
	{
		vector<vector<int>> paths(numCourses, vector<int>());
		vector<int> flag(numCourses, 0);

		for (int i = 0; i < prerequisites.size(); ++i)
		{
			paths[prerequisites[i][1]].push_back(prerequisites[i][0]);
			flag[prerequisites[i][0]]++;
		}

		vector<int> result;
		for (int i = 0; i < numCourses; ++i)
			if (flag[i] == 0)
				result.push_back(i);

		int idx = 0;
		while (idx < result.size())
		{
			int cur = result[idx];
			++idx;

			for (int i = 0; i < paths[cur].size(); ++i)
			{
				--flag[paths[cur][i]];
				if (flag[paths[cur][i]] == 0)
					result.push_back(paths[cur][i]);
			}
		}
		return idx == numCourses ? result : vector<int>();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
