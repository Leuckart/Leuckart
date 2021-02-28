/**************************************************
	> File Name:  Guide_5.03_ConvertStringToInteger.cpp
	> Author:     Leuckart
	> Time:       2020-10-10 18:41
**************************************************/

#include <iostream>
#include <cassert>
#include <climits>
#include <string>
using namespace std;

class Solution
{
public:
	static int convert(const string &str)
	{
		if (!isValid(str))
			return 0;

		bool flag_pos = str[0] != '-';
		const int MAX_Q = INT_MAX / 10;
		const int MAX_R = INT_MAX % 10;

		int result = 0;
		for (int i = flag_pos ? 0 : 1; i < str.length(); ++i)
		{
			int cur = str[i] - '0';
			if (!flag_pos && result == MAX_Q && cur == (MAX_R + 1))
				return INT_MIN;
			if ((result > MAX_Q ||
				 (result == MAX_Q && cur > MAX_R)))
				return 0;
			result = result * 10 + cur;
		}
		return flag_pos ? result : -result;
	}

private:
	static bool isValid(const string &str)
	{
		if (str.empty())
			return false;
		if (str[0] != '-' && (str[0] < '0' || str[0] > '9'))
			return false;
		if (str[0] == '-' && (str.length() == 1 || str[1] == '0'))
			return false;
		if (str[0] == '0' && str.length() > 1)
			return false;
		for (int i = 1; i < str.length(); ++i)
			if (str[i] < '0' || str[i] > '9')
				return false;
		return true;
	}
};

int main()
{
	assert(Solution::convert("2147483647") == INT_MAX);
	assert(Solution::convert("-2147483648") == INT_MIN);
	assert(Solution::convert("2147483648") == 0);
	assert(Solution::convert("-2147483649") == 0);
	return 0;
}
