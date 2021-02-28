/**************************************************
	> File Name:  Leet_032_LongestValidParentheses.cpp
	> Author:     Leuckart
	> Time:       2019-07-04 13:05
**************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		if (s.empty())
			return 0;

		vector<int> DP(s.length(), 0);
		for (int i = 1; i < s.length(); ++i)
		{
			if (s[i] == '(')
				continue;

			int pre = i - DP[i - 1] - 1;
			if (pre == 0 && s[pre] == '(')
				DP[i] = DP[i - 1] + 2;
			if (pre > 0 && s[pre] == '(')
				DP[i] = DP[i - 1] + 2 + DP[pre - 1];
		}
		return *max_element(DP.cbegin(), DP.cend());
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
