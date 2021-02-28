/**************************************************
	> File Name:  Guide_4.14_StringCross.cpp
	> Author:     Leuckart
	> Time:       2020-10-08 16:23
**************************************************/

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	static bool isCross(const string &str1, const string &str2, const string &target)
	{
		// dp[i][j] : str1[0:i]与str2[0:j]能否交错组成target[0,i+j+1]
		vector<vector<bool>> dp(str1.length() + 1, vector<bool>(str2.length() + 1, false));

		dp[0][0] = true;
		for (int i = 1; i <= str1.length(); ++i)
			dp[i][0] = dp[i - 1][0] && str1[i - 1] == target[i - 1];
		for (int i = 1; i <= str2.length(); ++i)
			dp[0][i] = dp[0][i - 1] && str2[i - 1] == target[i - 1];

		for (int i = 1; i <= str1.length(); ++i)
		{
			for (int j = 1; j <= str2.length(); ++j)
			{
				if ((str1[i - 1] == target[i + j - 1] && dp[i - 1][j]) ||
					(str2[j - 1] == target[i + j - 1] && dp[i][j - 1]))
					dp[i][j] = true;
			}
		}
		return dp.back().back();
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::isCross("1234", "abcd", "1a23bcd4") == true);
	return 0;
}
