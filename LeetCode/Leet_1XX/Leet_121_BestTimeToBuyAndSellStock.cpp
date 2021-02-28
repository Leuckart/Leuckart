/**************************************************
	> File Name:  Leet_121_BestTimeToBuyAndSellStock.cpp
	> Author:     Leuckart
	> Time:       2020-04-12 23:32
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(const vector<int> &prices)
	{
		if (prices.size() < 2)
			return 0;

		int max_profit = 0;
		int min_price = prices[0];

		for (int i = 1; i < prices.size(); ++i)
		{
			max_profit = max(max_profit, prices[i] - min_price);
			min_price = min(min_price, prices[i]);
		}
		return max_profit;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
