/**************************************************
	> File Name:  Leet_115_DistinctSubsequences.cpp
	> Author:     Leuckart
	> Time:       2019-08-05 20:47
**************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numDistinct(const string &s, const string &t)
	{
		if (s.length() < t.length())
			return 0;

		// DP[i][j]: T[0, j) 在 S[0, i) 的子串中出现的次数
		vector<vector<long>> DP(s.length() + 1, vector<long>(t.length() + 1, 0));
		for (int i = 0; i <= s.length(); ++i)
			DP[i][0] = 1;

		for (int i = 1; i <= s.length(); ++i)
		{
			for (int j = 1; j <= t.length(); ++j)
			{
				DP[i][j] = DP[i - 1][j];
				if (s[i - 1] == t[j - 1])
					DP[i][j] += DP[i - 1][j - 1];
			}
		}
		return DP.back().back();
	}

	int numDistinct_v2(const string &s, const string &t)
	{
		if (s.length() < t.length())
			return 0;

		vector<long> DP(t.length() + 1, 0);
		DP[0] = 1;

		for (int i = 1; i <= s.length(); ++i)
		{
			int past_lft = 1;
			for (int j = 1; j <= t.length(); ++j)
			{
				int past_cur = DP[j];
				DP[j] += (s[i - 1] == t[j - 1] ? past_lft : 0);
				past_lft = past_cur;
			}
		}
		return DP.back();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
