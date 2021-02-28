/**************************************************
	> File Name:  Leet_028_ImplementStrStr.cpp
	> Author:     Leuckart
	> Time:       2019-06-23 21:49
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int strStr(const string haystack, const string needle)
	{
		if (needle.empty())
			return 0;
		if (haystack.size() < needle.size())
			return -1;

		for (int i = 0; i <= haystack.size() - needle.size(); ++i)
		{
			int j = 0;
			while (j < needle.size())
			{
				if (haystack[i + j] == needle[j])
					++j;
				else
					break;
			}
			if (j == needle.size())
				return i;
		}
		return -1;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
