/**************************************************
	> File Name:  Guide_4.13_EditCost.cpp
	> Author:     Leuckart
	> Time:       2020-10-08 15:16
**************************************************/

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	static int minCost(const string &str1, const string &str2, const int inc, const int dec, const int rep)
	{
		// dp[i][j] : str1[i]到str2[j]的编辑代价
		vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));
		for (int i = 1; i <= str1.length(); ++i)
			dp[i][0] = i * dec;
		for (int i = 1; i <= str2.length(); ++i)
			dp[0][i] = i * inc;

		for (int i = 1; i <= str1.length(); ++i)
		{
			for (int j = 1; j <= str2.length(); ++j)
			{
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i - 1][j - 1] + rep;

				dp[i][j] = min(dp[i][j], min(dp[i][j - 1] + inc, dp[i - 1][j] + dec));
			}
		}
		return dp.back().back();
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::minCost("abc", "adc", 5, 3, 2) == 2);
	return 0;
}
