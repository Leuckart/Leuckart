/**************************************************
	> File Name:  Sword_20_NumericStrings.cpp
	> Author:     Leuckart
	> Time:       2020-02-17 20:20
**************************************************/

// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

bool scanUnsignedInteger(const string &str, size_t &idx)
{
	size_t idx0 = idx;
	while (idx < str.length() && str[idx] >= '0' && str[idx] <= '9')
		++idx;
	return idx > idx0;
}

bool scanInteger(const string &str, size_t &idx)
{
	if (str[idx] == '+' || str[idx] == '-')
		++idx;
	return scanUnsignedInteger(str, idx);
}

bool isNumeric(const string &str)
{
	if (str.empty())
		return false;

	size_t idx = 0;
	bool numeric = scanInteger(str, idx);

	if (str[idx] == '.')
	{
		++idx;
		numeric = scanUnsignedInteger(str, idx) || numeric;
	}

	if (str[idx] == 'e' || str[idx] == 'E')
	{
		++idx;
		numeric = scanInteger(str, idx) && numeric;
	}
	return numeric && idx == str.length();
}

int main(int argc, char *argv[])
{
	assert(isNumeric("100") == true);
	assert(isNumeric("123.45e+6") == true);
	assert(isNumeric("+500") == true);
	assert(isNumeric("5e2") == true);
	assert(isNumeric("3.1416") == true);

	assert(isNumeric("600.") == true);
	assert(isNumeric("-.123") == true);
	assert(isNumeric("-1E-16") == true);
	assert(isNumeric("1.79769313486232E+308") == true);
	assert(isNumeric("12e") == false);

	assert(isNumeric("1a3.14") == false);
	assert(isNumeric("1+23") == false);
	assert(isNumeric("1.2.3") == false);
	assert(isNumeric("+-5") == false);
	assert(isNumeric("12e+5.4") == false);

	assert(isNumeric(".") == false);
	assert(isNumeric(".e1") == false);
	assert(isNumeric("e1") == false);
	assert(isNumeric("+.") == false);
	assert(isNumeric("") == false);

	return 0;
}
