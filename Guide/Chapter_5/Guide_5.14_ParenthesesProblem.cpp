/**************************************************
	> File Name:  Guide_5.14_ParenthesesProblem.cpp
	> Author:     Leuckart
	> Time:       2020-03-27 14:16
**************************************************/

#include <algorithm>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	static int maxLength(const string &str)
	{
		if (str.empty())
			return 0;

		// 以str[i]结尾的最长有效括号子串长度
		vector<int> dp(str.length(), 0);
		for (int i = 1; i < str.length(); ++i)
		{
			if (str[i] == ')')
			{
				int prev = i - dp[i - 1] - 1;
				if (prev >= 0 && str[prev] == '(')
				{
					dp[i] = dp[i - 1] + 2;
					if (prev > 0)
						dp[i] += dp[prev - 1];
				}
			}
		}
		return *max_element(dp.cbegin(), dp.cend());
	}
};

int main()
{
	assert(Solution::maxLength("()(()()(") == 4);
	assert(Solution::maxLength("((())())") == 8);
	assert(Solution::maxLength("(())(()(()))") == 12);
	return 0;
}
