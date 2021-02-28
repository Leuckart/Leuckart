/**************************************************
	> File Name:  Leet_123_BestTimeToBuyAndSellStock3.cpp
	> Author:     Leuckart
	> Time:       2020-04-13 22:58
**************************************************/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(const vector<int> &prices)
	{
		int buy1 = INT_MAX;
		int sell1 = 0;
		int buy2 = INT_MAX;
		int sell2 = 0;

		for (int i = 0; i < prices.size(); ++i)
		{
			sell1 = max(sell1, prices[i] - buy1);
			buy1 = min(buy1, prices[i]);
			sell2 = max(sell2, prices[i] - buy2);
			buy2 = min(buy2, prices[i] - sell1);
		}
		return sell2;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
