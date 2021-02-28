/**************************************************
	> File Name:  Leet_076_MinimumWindowSubstring.cpp
	> Author:     Leuckart
	> Time:       2019-07-22 16:40
**************************************************/

#include <iostream>
#include <climits>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	string minWindow(const string &s, const string &t)
	{
		vector<int> dict(256, 0);
		for (int i = 0; i < t.length(); ++i)
			dict[t[i]]++;

		int min_beg = 0;
		int min_len = INT_MAX;
		for (int beg = 0, end = 0, count = 0; end < s.length(); ++end)
		{
			dict[s[end]]--;
			if (dict[s[end]] >= 0)
				++count;

			while (count == t.length())
			{
				if (end - beg + 1 < min_len)
				{
					min_beg = beg;
					min_len = end - beg + 1;
				}

				dict[s[beg]]++;
				if (dict[s[beg]] > 0)
					--count;
				++beg;
			}
		}
		return min_len == INT_MAX ? "" : s.substr(min_beg, min_len);
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
