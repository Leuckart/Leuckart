/**************************************************
	> File Name:  Leet_122_BestTimeToBuyAndSellStock2.cpp
	> Author:     Leuckart
	> Time:       2020-04-13 00:07
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(const vector<int> &prices)
	{
		int max_profit = 0;
		for (int i = 0; i < prices.size() - 1; ++i)
			if (prices[i] < prices[i + 1])
				max_profit += prices[i + 1] - prices[i];
		return max_profit;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
