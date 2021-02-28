/**************************************************
	> File Name:  Leet_214_ShortestPalindrome.cpp
	> Author:     Leuckart
	> Time:       2020-09-23 20:57
**************************************************/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string shortestPalindrome(string s)
	{
		vector<int> fail(s.length(), -1);
		for (int i = 1; i < s.length(); ++i)
		{
			int j = fail[i - 1];
			while (j != -1 && s[j + 1] != s[i])
				j = fail[j];

			if (s[j + 1] == s[i])
				fail[i] = j + 1;
		}

		int best = -1;
		for (int i = s.length() - 1; i >= 0; --i)
		{
			while (best != -1 && s[best + 1] != s[i])
				best = fail[best];

			if (s[best + 1] == s[i])
				++best;
		}

		string add = (best == s.length() - 1 ? "" : s.substr(best + 1, s.length()));
		reverse(add.begin(), add.end());
		return add + s;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
