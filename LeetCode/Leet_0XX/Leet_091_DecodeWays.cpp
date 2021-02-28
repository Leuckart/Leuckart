/**************************************************
	> File Name:  Leet_091_DecodeWays.cpp
	> Author:     Leuckart
	> Time:       2019-07-27 15:49
**************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numDecodings(const string s)
	{
		if (s.empty())
			return 0;

		vector<int> DP(s.length() + 1, 0);
		DP[s.length()] = 1;
		DP[s.length() - 1] = s.back() != '0';

		for (int i = s.length() - 2; i >= 0; --i)
		{
			if (s[i] == '0')
				continue;

			if (s[i] > '2' || (s[i] == '2' && s[i + 1] > '6'))
				DP[i] = DP[i + 1];
			else
				DP[i] = DP[i + 1] + DP[i + 2];
		}
		return DP[0];
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
