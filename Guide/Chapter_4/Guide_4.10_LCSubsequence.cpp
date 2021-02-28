/**************************************************
	> File Name:  Guide_4.10_LCSubsequence.cpp
	> Author:     Leuckart
	> Time:       2020-10-07 15:16
**************************************************/

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	static string lcse(const string &str1, const string &str2)
	{
		if (str1.empty() || str2.empty())
			return "";

		// dp[i][j] : str1[0:i]与str2[0:j]的最长公共子序列长度
		vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), 0));
		dp[0][0] = str1[0] == str2[0];

		for (int i = 1; i < str2.length(); ++i)
			dp[0][i] = dp[0][i - 1] || str1[0] == str2[i];
		for (int i = 1; i < str1.length(); ++i)
			dp[i][0] = dp[i - 1][0] || str1[i] == str2[0];

		for (int i = 1; i < str1.length(); ++i)
		{
			for (int j = 1; j < str2.length(); ++j)
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				if (str1[i] == str2[j])
					dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
			}
		}

		string result(dp.back().back(), ' ');
		int index = result.length() - 1;
		for (int i = str1.length() - 1, j = str2.length() - 1; index >= 0;)
		{
			if (i > 0 && dp[i][j] == dp[i - 1][j])
				--i;
			else if (j > 0 && dp[i][j] == dp[i][j - 1])
				--j;
			else
			{
				result[index] = str1[i];
				--index;
				--i;
				--j;
			}
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::lcse("A1BC2D3EFGH45I6JK7LMN", "12OPQ3RST4U5V6W7XYZ") == "1234567");
	return 0;
}
