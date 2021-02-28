/**************************************************
	> File Name:  Leet_067_AddBinary.cpp
	> Author:     Leuckart
	> Time:       2019-06-28 00:37
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string addBinary(const string a, const string b)
	{
		if (a.length() < b.length())
			return addBinary(b, a);

		string result = a;
		bool flag = false;
		for (int i = 0; i < b.length(); ++i)
		{
			int tmp = result[result.length() - 1 - i] - '0' + b[b.length() - 1 - i] - '0' + flag;
			result[result.length() - 1 - i] = tmp % 2 + '0';
			flag = tmp / 2;
		}

		int idx = result.length() - b.length() - 1;
		while (idx >= 0 && flag)
		{
			int tmp = result[idx] - '0' + flag;
			result[idx] = tmp % 2 + '0';
			flag = tmp / 2;
			--idx;
		}
		if (idx < 0 && flag)
			result = '1' + result;
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
