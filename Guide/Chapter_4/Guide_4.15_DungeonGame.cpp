/**************************************************
	> File Name:  Guide_4.15_DungeonGame.cpp
	> Author:     Leuckart
	> Time:       2020-10-08 16:57
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int minHP(const vector<vector<int>> &data)
	{
		if (data.empty() || data[0].empty())
			return 0;

		// dp[i][j] : 进入(i,j)所需的最少血量
		vector<vector<int>> dp(data.size(), vector<int>(data[0].size(), 0));
		dp.back().back() = data.back().back() > 0 ? 1 : (1 - data.back().back());

		for (int i = data[0].size() - 2; i >= 0; --i)
			dp.back()[i] = max(dp.back()[i + 1] - data.back()[i], 1);

		for (int i = data.size() - 2; i >= 0; --i)
		{

			dp[i].back() = max(dp[i + 1].back() - data[i].back(), 1);
			for (int j = data[0].size() - 2; j >= 0; --j)
			{
				int val1 = max(dp[i + 1][j] - data[i][j], 1);
				int val2 = max(dp[i][j + 1] - data[i][j], 1);
				dp[i][j] = min(val1, val2);
			}
		}
		return dp.front().front();
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::minHP({{-2, -3, 3}, {-5, -10, 1}, {0, 30, -5}}) == 7);
	return 0;
}
