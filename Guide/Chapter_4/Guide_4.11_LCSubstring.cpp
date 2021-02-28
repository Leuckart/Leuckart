/**************************************************
	> File Name:  Guide_4.11_LCSubstring.cpp
	> Author:     Leuckart
	> Time:       2020-10-07 18:24
**************************************************/

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class Solution
{
public:
	static string lcst(const string &str1, const string &str2)
	{
		if (str1.empty() || str2.empty())
			return "";

		int row = 0;				 // 斜线开始的行
		int col = str2.length() - 1; // 斜线开始的列

		int max_len = 0;
		int max_end = 0;
		while (row < str1.length())
		{
			int i = row; // str1[i]
			int j = col; // str2 [j]
			int cur_len = 0;

			while (i < str1.length() && j < str2.length())
			{
				if (str1[i] == str2[j])
					++cur_len;
				else
					cur_len = 0;

				if (cur_len > max_len)
				{
					max_len = cur_len;
					max_end = i;
				}

				++i;
				++j;
			}

			if (col > 0)
				--col;
			else
				++row;
		}
		return str1.substr(max_end - max_len + 1, max_len);
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::lcst("ABC1234567DEFG", "HIJKL1234567MNOP") == "1234567");
	return 0;
}
