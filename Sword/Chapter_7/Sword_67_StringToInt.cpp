/**************************************************
	> File Name:  Sword_67_StringToInt.cpp
	> Author:     Leuckart
	> Time:       2020-02-28 04:39
**************************************************/

// 面试题67：把字符串转换成整数
// 题目：请你写一个函数StrToInt，实现把字符串转换成整数这个功能。当然，不
// 能使用atoi或者其他类似的库函数。

#include <iostream>
#include <climits>
#include <cassert>
using namespace std;

bool beNum = false;

int StrToInt(const string &str)
{
	beNum = false;
	if (str.empty())
		return 0;

	long long number = 0;
	bool pos_flag = true;
	int idx = 0;

	if (str[idx] == '+' || str[idx] == '-')
	{
		pos_flag = str[idx++] == '+';
		if (idx == str.length())
			return 0;
	}

	while (idx < str.length())
	{
		if (str[idx] < '0' || str[idx] > '9')
			return 0;

		number = number * 10 + str[idx] - '0';
		idx++;
	}

	number *= pos_flag ? 1 : -1;
	if (number > INT_MAX || number < INT_MIN)
		return 0;

	beNum = true;
	return number;
}

int main(int argc, char *argv[])
{
	assert(StrToInt("123") == 123 && beNum == true);
	assert(StrToInt("+123") == 123 && beNum == true);
	assert(StrToInt("-123") == -123 && beNum == true);

	assert(StrToInt("1a33") == 0 && beNum == false);
	assert(StrToInt("+0") == 0 && beNum == true);
	assert(StrToInt("-0") == 0 && beNum == true);
	assert(StrToInt("") == 0 && beNum == false);

	assert(StrToInt("+2147483647") == 2147483647 && beNum == true);
	assert(StrToInt("-2147483647") == -2147483647 && beNum == true);
	assert(StrToInt("+2147483648") == 0 && beNum == false);

	assert(StrToInt("-2147483648") == -2147483648 && beNum == true);
	assert(StrToInt("+2147483648") == 0 && beNum == false);
	assert(StrToInt("-2147483649") == 0 && beNum == false);

	assert(StrToInt("+") == 0 && beNum == false);
	assert(StrToInt("-") == 0 && beNum == false);

	return 0;
}
