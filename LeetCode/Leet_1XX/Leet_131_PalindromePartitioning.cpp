/**************************************************
        > File Name:  Leet_131_PalindromePartitioning.cpp
        > Author:     Leuckart
        > Time:       2020-09-02 20:45
**************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> partition(string s)
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

		vector<vector<string>> result;
		partitionCore(DP, s, 0, {}, result);
		return result;
	}

private:
	void partitionCore(const vector<vector<bool>> &DP, const string &s, int start, vector<string> path, vector<vector<string>> &result)
	{
		if (start == s.length())
		{
			result.push_back(path);
			return;
		}

		for (int i = start; i < s.length(); ++i)
		{
			if (DP[start][i])
			{
				path.push_back(s.substr(start, i - start + 1));
				partitionCore(DP, s, i + 1, path, result);
				path.pop_back();
			}
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
