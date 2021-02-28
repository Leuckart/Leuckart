/**************************************************
	> File Name:  Leet_005_LongestPalindromicSubstring.cpp
	> Author:     Leuckart
	> Time:       2019-04-13 16:14
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		if (s.length() < 1)
			return "";

		int max_pos = 0;
		int max_len = 1;
		for (int i = 0; i < s.length();)
		{
			if (s.length() - i <= max_len / 2)
				break;

			int lhs = i;
			int rhs = i;

			// 越过相同的字符
			while (rhs < s.length() - 1 && s[rhs] == s[rhs + 1])
				++rhs;
			
			// 更新 i 坐标
			i = rhs + 1;

			// 向两边扩张
			while (lhs > 0 && rhs < s.length() - 1 && s[lhs - 1] == s[rhs + 1])
			{
				--lhs;
				++rhs;
			}

			if (rhs - lhs + 1 > max_len)
			{
				max_len = rhs - lhs + 1;
				max_pos = lhs;
			}
		}
		return s.substr(max_pos, max_len);
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
