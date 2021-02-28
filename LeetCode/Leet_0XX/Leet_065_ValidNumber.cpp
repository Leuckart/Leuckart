/**************************************************
	> File Name:  Leet_065_ValidNumber.cpp
	> Author:     Leuckart
	> Time:       2019-07-18 14:45
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	bool isNumber(const string s)
	{
		bool flag_sign = false;
		bool flag_dot = false;
		bool flag_exp = false;
		bool flag_num = false;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				if (i < s.size() - 1 && s[i + 1] != ' ' &&
					(flag_sign || flag_dot || flag_exp || flag_num))
					return false;
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ')
					return false;
				flag_sign = true;
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				flag_num = true;
			}
			else if (s[i] == '.')
			{
				if (flag_dot || flag_exp)
					return false;
				flag_dot = true;
			}
			else if (s[i] == 'e')
			{
				if (flag_exp || !flag_num)
					return false;
				flag_exp = true;
				flag_num = false;
			}
			else
				return false;
		}
		return flag_num;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
