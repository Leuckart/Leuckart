/**************************************************
	> File Name:  Guide_5.13_PalindromeString.cpp
	> Author:     Leuckart
	> Time:       2020-10-11 15:08
**************************************************/

#include <iostream>
#include <cassert>
#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	static string getPalindrome(const string &str)
	{
		if (str.length() < 2)
			return str;

		vector<vector<int>> dp(str.length(), vector<int>(str.length(), 0));
		for (int i = str.length() - 2; i >= 0; --i)
		{
			dp[i][i + 1] = str[i] != str[i + 1];
			for (int j = i + 2; j < str.length(); ++j)
			{
				if (str[i] == str[j])
					dp[i][j] = dp[i + 1][j - 1];
				else
					dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
			}
		}

		string result(str.length() + dp.front().back(), ' ');
		for (int l = 0, r = str.length() - 1, res_l = 0, res_r = result.length() - 1; l <= r;)
		{
			if (str[l] == str[r])
			{
				result[res_l++] = str[l++];
				result[res_r--] = str[r--];
			}
			else if (dp[l][r - 1] < dp[l + 1][r])
			{
				result[res_l++] = str[r];
				result[res_r--] = str[r--];
			}
			else
			{
				result[res_l++] = str[l];
				result[res_r--] = str[l++];
			}
		}
		return result;
	}
};

int main()
{
	assert(Solution::getPalindrome("AB1CD2EFG3H43IJK2L1MN") == "ABNM1CDL2EFGKJI3H4H3IJKGFE2LDC1MNBA");
	return 0;
}
