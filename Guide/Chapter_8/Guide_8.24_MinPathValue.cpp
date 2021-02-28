/**************************************************
	> File Name:  Guide_8.24_MinPathValue.cpp
	> Author:     Leuckart
	> Time:       2020-10-21 04:39
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	static int minPath(const vector<vector<int>> &data)
	{
		if (data.empty() || data[0].empty())
			return 0;

		int result = 0;
		queue<pair<int, int>> Q;
		vector<vector<int>> dp(data.size(), vector<int>(data[0].size(), 0));
		Q.push(make_pair(0, 0));
		dp[0][0] = 1;

		while (!Q.empty())
		{
			int size = Q.size();
			while (size-- > 0)
			{
				pair<int, int> cur = Q.front();
				Q.pop();
				walkTo(data, dp, Q, dp[cur.first][cur.second], cur.first + 1, cur.second);
				walkTo(data, dp, Q, dp[cur.first][cur.second], cur.first - 1, cur.second);
				walkTo(data, dp, Q, dp[cur.first][cur.second], cur.first, cur.second + 1);
				walkTo(data, dp, Q, dp[cur.first][cur.second], cur.first, cur.second - 1);
			}
		}
		return dp.back().back();
	}

private:
	static void walkTo(const vector<vector<int>> &data, vector<vector<int>> &dp, queue<pair<int, int>> &Q,
					   const int val, const int i, const int j)
	{
		if (i < 0 || i == data.size() ||
			j < 0 || j == data[0].size() ||
			data[i][j] == 0 ||
			dp[i][j] > 0)
			return;
		dp[i][j] = val + 1;
		Q.push(make_pair(i, j));
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::minPath({{1, 0, 1, 1, 1},
							  {1, 0, 1, 0, 1},
							  {1, 1, 1, 0, 1},
							  {0, 0, 0, 0, 1}}) == 12);
	assert(Solution::minPath({{1, 1, 0, 1, 1},
							  {1, 1, 1, 1, 1},
							  {1, 1, 1, 1, 1},
							  {0, 0, 0, 0, 1}}) == 8);
	return 0;
}
