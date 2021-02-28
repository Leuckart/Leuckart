/**************************************************
	> File Name:  Leet_008_StringToInteger.cpp
	> Author:     Leuckart
	> Time:       2019-06-08 17:53
**************************************************/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
	int myAtoi(const string str)
	{
		int index = 0;
		while (str[index] == ' ')
			++index;

		if ((str[index] < '0' || str[index] > '9') &&
			str[index] != '+' &&
			str[index] != '-')
			return 0;

		bool be_positive = true;
		if (str[index] == '+')
			++index;
		else if (str[index] == '-')
		{
			++index;
			be_positive = false;
		}

		int ans = 0;
		while (index < str.length() && str[index] >= '0' && str[index] <= '9')
		{
			if ((ans > 214748364) ||
				(ans == 214748364 && ((str[index] - '0') > 7)))
				return be_positive ? INT_MAX : INT_MIN;

			ans = ans * 10 + (str[index] - '0');
			++index;
		}
		return be_positive ? ans : -ans;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
