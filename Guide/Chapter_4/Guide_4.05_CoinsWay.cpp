/**************************************************
	> File Name:  Guide_4.05_CoinsWay.cpp
	> Author:     Leuckart
	> Time:       2020-10-05 20:04
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int coins(const vector<int> &data, const int aim)
	{
		if (data.empty() || aim < 0)
			return 0;

		vector<int> dp(aim + 1, 0);
		for (int i = 0; i * data[0] <= aim; ++i)
			dp[i * data[0]] = 1;

		// 第i轮的dp[j]表示：使用data[1:i]，可凑满j元的方式总数
		for (int i = 1; i < data.size(); ++i)
		{
			for (int j = 1; j <= aim; ++j)
			{
				if (data[i] <= j)
					dp[j] += dp[j - data[i]];
			}
		}
		return dp.back();
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::coins({10, 5, 1, 25}, 20000) == 1070270201);
	return 0;
}
