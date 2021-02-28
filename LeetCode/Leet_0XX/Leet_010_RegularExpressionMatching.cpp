/**************************************************
	> File Name:  Leet_010_RegularExpressionMatching.cpp
	> Author:     Leuckart
	> Time:       2019-06-09 15:04
**************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isMatch(string s, string p)
	{
		if (s.empty() && p.empty())
			return true;
		if (!s.empty() && p.empty())
			return false;
		if (s.empty())
		{
			for (int i = 1; i < p.length(); i += 2)
				if (p[i] != '*')
					return false;
			return p.length() % 2 ? false : true;
		}

		vector<vector<bool>> DP(s.length() + 1, vector<bool>(p.length() + 1, false));

		DP[0][0] = true;
		DP[1][1] = s[0] == p[0] || p[0] == '.';
		for (int pi = 2; pi <= p.length(); pi += 2)
			DP[0][pi] = DP[0][pi - 2] && p[pi - 1] == '*';

		for (int si = 1; si <= s.length(); ++si)
		{
			for (int pi = 2; pi <= p.length(); ++pi)
			{
				if (p[pi - 1] == '*')
				{
					DP[si][pi] = DP[si][j - 2] ||
								 (DP[si - 1][j] && (s[si - 1] == p[pi - 2] || p[pi - 2] == '.'));
				}
				else
				{
					DP[si][pi] = DP[si - 1][pi - 1] &&
								 (s[si - 1] == p[pi - 1] || p[pi - 1] == '.');
				}
			}
		}
		return DP[s.length()][p.length()];
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
