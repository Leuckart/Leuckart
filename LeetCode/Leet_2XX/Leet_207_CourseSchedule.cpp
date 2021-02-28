/**************************************************
	> File Name:  Leet_207_CourseSchedule.cpp
	> Author:     Leuckart
	> Time:       2020-09-18 20:57
**************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	bool canFinish(int numCourses, const vector<vector<int>> &prerequisites)
	{
		vector<vector<int>> paths(numCourses, vector<int>());
		vector<int> flag(numCourses, 0);

		for (int i = 0; i < prerequisites.size(); ++i)
		{
			paths[prerequisites[i][1]].push_back(prerequisites[i][0]);
			flag[prerequisites[i][0]]++;
		}

		queue<int> Q;
		for (int i = 0; i < numCourses; ++i)
			if (flag[i] == 0)
				Q.push(i);

		int result = 0;
		while (!Q.empty())
		{
			int cur = Q.front();
			Q.pop();

			for (int i = 0; i < paths[cur].size(); ++i)
			{
				--flag[paths[cur][i]];
				if (flag[paths[cur][i]] == 0)
					Q.push(paths[cur][i]);
			}
			++result;
		}
		return result == numCourses;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
