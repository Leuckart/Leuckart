/**************************************************
	> File Name:  Leet_140_WordBreak2.cpp
	> Author:     Leuckart
	> Time:       2020-09-03 14:44
**************************************************/

#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{

public:
	vector<string> wordBreak(string s, vector<string> &wordDict)
	{
		unordered_set<string> dict(wordDict.begin(), wordDict.end());
		vector<vector<int>> DP(s.length() + 1, vector<int>());
		DP[0].push_back(0);

		for (int i = 0; i < s.length(); ++i)
		{
			for (int j = i; j >= 0; j--)
			{
				if (DP[j + 1 - 1].size() > 0 && dict.find(s.substr(j, i - j + 1)) != dict.end())
				{
					DP[i + 1].push_back(j);
				}
			}
		}

		vector<string> ans;
		string path = "";
		wordBreakCore(s.length() - 1, DP, ans, path, s);
		return ans;
	}

private:
	void wordBreakCore(int en, vector<vector<int>> &DP, vector<string> &ans, string &path, string &s)
	{
		if (en == -1)
		{
			path.pop_back();
			ans.push_back(path);
			return;
		}

		for (auto st : DP[en + 1])
		{
			string next = s.substr(st, en - st + 1) + " " + path;
			wordBreakCore(st - 1, DP, ans, next, s);
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
