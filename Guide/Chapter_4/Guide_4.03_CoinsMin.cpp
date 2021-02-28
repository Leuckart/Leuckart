/**************************************************
	> File Name:  Guide_4.03_CoinsMin.cpp
	> Author:     Leuckart
	> Time:       2020-10-05 09:23
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int minCoins(const vector<int> &data, const int aim)
	{
		if (data.empty() || aim < 0)
			return -1;

		// dp[i][j] : 从第i个元素起，可凑满j元的最小纸币数
		vector<vector<int>> dp(data.size() + 1, vector<int>(aim + 1, -1));
		dp[data.size()][0] = 0;

		for (int i = data.size() - 1; i >= 0; --i)
		{
			for (int rest = 0; rest <= aim; ++rest)
			{
				if (dp[i + 1][rest] != -1)
					dp[i][rest] = dp[i + 1][rest];

				if (rest >= data[i] && dp[i][rest - data[i]] != -1)
				{
					if (dp[i][rest] != -1)
						dp[i][rest] = min(1 + dp[i][rest - data[i]], dp[i][rest]);
					else
						dp[i][rest] = 1 + dp[i][rest - data[i]];
				}
			}
		}
		return dp[0][aim];
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::minCoins({5, 2, 3}, 20) == 4);
	return 0;
}
