/**************************************************
	> File Name:  Guide_5.02_IsRotation.cpp
	> Author:     Leuckart
	> Time:       2020-10-10 11:15
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	static bool isRotation(const string &str1, const string &str2)
	{
		if (str1.length() != str2.length())
			return false;

		return kmpFind(str1 + str1, str2) != -1;
	}

private:
	static int kmpFind(const string &str1, const string &str2)
	{
		if (str1.length() < str2.length())
			return -1;

		const vector<int> next = getNext(str2);
		int i = 0;
		int j = 0;
		while (i < str1.length() && j < str2.length())
		{
			if (str1[i] == str2[j])
			{
				++i;
				++j;
			}
			else if (next[j] == -1)
				++i;
			else
				j = next[j];
		}
		return j == str2.length() ? (i - j) : -1;
	}

	static vector<int> getNext(const string &str)
	{
		if (str.length() == 1)
			return {-1};

		vector<int> next(str.length(), 0);
		next[0] = -1;
		next[1] = 0;

		for (int i = 2, cn = 0; i < str.length(); ++i)
		{
			if (str[i - 1] == str[cn])
			{
				++cn;
				next[i] = cn;
				++i;
			}
			else if (cn > 0)
				cn = next[cn];
			else
			{
				next[i] = 0;
				++i;
			}
		}
		return next;
	}
};

int main()
{
	assert(Solution::isRotation("cdab", "abcd") == true);
	assert(Solution::isRotation("1ab2", "ab12") == false);
	assert(Solution::isRotation("2ab1", "ab12") == true);
	return 0;
}
