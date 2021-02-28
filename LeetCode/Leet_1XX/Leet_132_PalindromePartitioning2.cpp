/**************************************************
	> File Name:  Leet_132_PalindromePartitioning2.cpp
	> Author:     Leuckart
	> Time:       2020-09-02 22:20
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int minCut(string s)
	{
		vector<vector<bool>> DP(s.length(), vector<bool>(s.length(), false));
		for (int len = 1; len <= s.length(); ++len)
		{
			for (int i = 0; i <= s.length() - len; ++i)
			{
				int j = i + len - 1;
				DP[i][j] = (s[i] == s[j]) && (len < 3 || DP[i + 1][j - 1]);
			}
		}

		vector<int> Min(s.length(), 0);
		for (int i = 1; i < s.length(); ++i)
		{
			int cur_min = INT32_MAX;
			for (int j = 0; j <= i; ++j)
			{
				if (DP[j][i])
				{
					if (j == 0)
						cur_min = 0;
					else
						cur_min = min(cur_min, 1 + Min[j - 1]);
				}
			}
			Min[i] = cur_min;
		}
		return Min[s.length() - 1];
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
