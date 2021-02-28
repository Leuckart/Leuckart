/**************************************************
	> File Name:  Leet_044_WildcardMatching.cpp
	> Author:     Leuckart
	> Time:       2019-07-13 21:16
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	bool isMatch(string s, string p)
	{
		vector<vector<bool>> DP(s.length() + 1, vector<bool>(p.length() + 1, false));
		DP[0][0] = true;
		for (int pi = 1; pi <= p.length(); ++pi)
			DP[0][pi] = DP[0][pi - 1] && p[pi - 1] == '*';

		for (int si = 1; si <= s.length(); ++si)
		{
			for (int pi = 1; pi <= p.length(); ++pi)
			{
				if (p[pi - 1] == '*')
					DP[si][pi] = DP[si][pi - 1] || DP[si - 1][pi];
				else if (p[pi - 1] == '?')
					DP[si][pi] = DP[si - 1][pi - 1];
				else
					DP[si][pi] = DP[si - 1][pi - 1] && s[si - 1] == p[pi - 1];
			}
		}
		return DP.back().back();
	}

	bool isMatch_Greedy(string s, string p)
	{
		int s_len = s.length(), p_len = p.length();
		int s_ptr = 0, p_ptr = 0;
		int s_matched = -1, p_star = -1;

		while (s_ptr < s_len)
		{
			if (p_ptr < p_len && p[p_ptr] == '*')
			{
				s_matched = s_ptr;
				p_star = p_ptr;
				p_ptr++;
			}
			else if (p_ptr < p_len && (p[p_ptr] == '?' || p[p_ptr] == s[s_ptr]))
			{
				s_ptr++;
				p_ptr++;
			}
			else if (p_star > -1)
			{
				s_ptr = s_matched + 1;
				p_ptr = p_star + 1;
				s_matched++; // Match A More Character.
			}
			else
				return false;
		}
		while (p_ptr < p_len && p[p_ptr] == '*')
			p_ptr++;

		return p_ptr == p_len;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
