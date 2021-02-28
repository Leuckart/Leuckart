/**************************************************
	> File Name:  Leet_139_WordBreak.cpp
	> Author:     Leuckart
	> Time:       2020-09-03 14:01
**************************************************/

#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	bool wordBreak(string s, vector<string> &wordDict)
	{
		unordered_set<string> dict(wordDict.begin(), wordDict.end());
		vector<bool> DP(s.length(), false);
		DP[0] = dict.find(s.substr(0, 1)) != dict.end();

		for (int i = 1; i < s.length(); ++i)
		{
			DP[i] = dict.find(s.substr(0, i + 1)) != dict.end();
			for (int j = 0; j < i; ++j)
			{
				if (DP[j] && dict.find(s.substr(j + 1, i - j)) != dict.end())
				{
					DP[i] = true;
					break;
				}
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
