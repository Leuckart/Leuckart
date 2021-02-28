/**************************************************
	> File Name:  Leet_188_BestTimeToBuyAndSellStock5.cpp
	> Author:     Leuckart
	> Time:       2020-09-06 12:59
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(int k, const vector<int> &prices)
	{
		if (prices.empty())
			return 0;

		if (k >= prices.size() / 2)
		{
			int result0 = 0;
			int result1 = -prices[0];

			for (int i = 1; i < prices.size(); ++i)
			{
				int tmp = result0;
				result0 = max(result0, result1 + prices[i]);
				result1 = max(result1, result0 - prices[i]);
			}
			return max(result0, result1);
		}

		vector<vector<int>> DP(k + 1, vector<int>{0, -prices[0]});
		for (int i = 0; i < prices.size(); ++i)
		{
			for (int j = 1; j <= k; ++j)
			{
				DP[j - 1][1] = max(DP[j - 1][1], DP[j - 1][0] - prices[i]);
				DP[j][0] = max(DP[j][0], DP[j - 1][1] + prices[i]);
			}
		}
		return DP[k][0];
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
