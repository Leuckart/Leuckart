/**************************************************
	> File Name:  Guide_5.01_IsDeformation.cpp
	> Author:     Leuckart
	> Time:       2020-03-20 12:57
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	static bool isDeformation(const string &str1, const string &str2)
	{
		if (str1.length() != str2.length())
			return false;

		vector<int> table(256, 0);
		for (int i = 0; i < str1.length(); ++i)
			table[str1[i]]++;
		for (int i = 0; i < str2.length(); ++i)
			table[str2[i]]--;

		for (int i = 0; i < 256; ++i)
			if (table[i] != 0)
				return false;
		return true;
	}
};

int main()
{
	assert(Solution::isDeformation("abcabcabc", "bcacbaacb") == true);
	return 0;
}
