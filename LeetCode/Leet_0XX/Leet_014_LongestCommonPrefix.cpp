/**************************************************
	> File Name:  Leet_014_LongestCommonPrefix.cpp
	> Author:     Leuckart
	> Time:       2019-04-12 05:01
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	string longestCommonPrefix(const vector<string> &strs)
	{
		if (strs.empty())
			return "";

		string ans;
		for (int i = 0; i < strs[0].length(); ++i)
		{
			char ch = strs[0][i];
			bool flag = true;
			for (int j = 0; j < strs.size(); ++j)
			{
				if (strs[j][i] != ch)
				{
					flag = false;
					break;
				}
			}
			if (flag)
				ans += ch;
			else
				break;
		}
		return ans;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
