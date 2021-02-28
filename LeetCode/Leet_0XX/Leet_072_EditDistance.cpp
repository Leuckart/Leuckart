/**************************************************
	> File Name:  Leet_072_EditDistance.cpp
	> Author:     Leuckart
	> Time:       2019-07-21 16:26
**************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDistance(const string &word1, const string &word2)
	{
		// DP[i][j]: 从 word1[0,i) 到 word2[0,j) 的最少转换步骤数
		vector<vector<int>> DP(word1.length() + 1, vector<int>(word2.length() + 1, 0));
		for (int i = 0; i <= word2.length(); ++i)
			DP[0][i] = i;
		for (int i = 0; i <= word1.length(); ++i)
			DP[i][0] = i;

		for (int i = 1; i <= word1.length(); ++i)
		{
			for (int j = 1; j <= word2.length(); ++j)
			{
				if (word1[i - 1] == word2[j - 1])
					DP[i][j] = DP[i - 1][j - 1];
				else
					DP[i][j] = 1 + min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1]));
			}
		}
		return DP.back().back();
	}

	int minDistance_v2(const string &word1, const string &word2)
	{
		vector<int> pre(word2.size() + 1, 0);
		vector<int> cur(word2.size() + 1, 0);
		for (int i = 1; i <= word2.size(); ++i)
			pre[i] = i;

		for (int i = 1; i <= word1.size(); ++i)
		{
			fill(cur.begin(), cur.end(), 0);
			cur[0] = i;
			for (int j = 1; j <= word2.size(); ++j)
			{
				if (word1[i - 1] == word2[j - 1])
					cur[j] = pre[j - 1];
				else
					cur[j] = min(cur[j - 1], min(pre[j - 1], pre[j])) + 1;
			}
			pre = cur;
		}
		return pre.back();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
