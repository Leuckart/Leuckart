/**************************************************
	> File Name:  Leet_038_CountAndSay.cpp
	> Author:     Leuckart
	> Time:       2019-07-03 21:41
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string countAndSay(int n)
	{
		string ans = "1";
		for (int iter = 1; iter < n; ++iter)
		{
			string cur;
			for (int i = 0; i < ans.length(); ++i)
			{
				int count = 1;
				while (i < ans.length() - 1 && ans[i] == ans[i + 1])
				{
					++i;
					++count;
				}
				cur += to_string(count) + ans[i];
			}
			ans = cur;
		}
		return ans;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
