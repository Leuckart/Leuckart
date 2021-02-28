/**************************************************
	> File Name:  Leet_097_InterleavingString.cpp
	> Author:     Leuckart
	> Time:       2019-07-29 14:35
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	bool isInterleave(const string s1, const string s2, const string s3)
	{
		if (s1.length() + s2.length() != s3.length())
			return false;

		vector<vector<bool>> DP(s1.length() + 1, vector<bool>(s2.length() + 1, false)); //true?
		DP[0][0] = true;
		for (int i = 1; i <= s1.length(); ++i)
			DP[i][0] = DP[i - 1][0] && s1[i - 1] == s3[i - 1];
		for (int i = 1; i <= s2.length(); ++i)
			DP[0][i] = DP[0][i - 1] && s2[i - 1] == s3[i - 1];

		for (int i = 1; i <= s1.length(); ++i)
		{
			for (int j = 1; j <= s2.length(); ++j)
			{
				DP[i][j] = (DP[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
						   (DP[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		return DP.back().back();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
