/**************************************************
	> File Name:  Leet_003_LongestSubstring.cpp
	> Author:     Leuckart
	> Time:       2019-04-12 18:15
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(const string &s)
	{
		if (s.empty())
			return 0;

		int max_len = 1;
		for (int lhs = 0, rhs = 1; rhs < s.length(); ++rhs)
		{
			int search = s.find(s[rhs], lhs);
			if (search < rhs)
			{
				lhs = search + 1;
				continue;
			}
			max_len = max(max_len, rhs - lhs + 1);
		}
		return max_len;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
