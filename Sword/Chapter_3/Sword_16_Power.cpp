/**************************************************
	> File Name:  Sword_16_Power.cpp
	> Author:     Leuckart
	> Time:       2020-02-17 04:22
**************************************************/

// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。

#include <iostream>
#include <cassert>

double PowerRecursive(double base, int exponent)
{
	if (exponent == 1)
		return base;
	if (exponent % 2)
		return PowerRecursive(base, exponent / 2) * PowerRecursive(base, exponent / 2) * base;
	else
		return PowerRecursive(base, exponent / 2) * PowerRecursive(base, exponent / 2);
}

double Power(double base, int exponent)
{
	if (base == 0)
		return 0;
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	if (exponent > 0)
		return PowerRecursive(base, exponent);
	else
		return 1 / PowerRecursive(base, -exponent);
}

bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

int main(int argc, char *argv[])
{
	assert(equal(Power(2, 3), 8));
	assert(equal(Power(-2, 3), -8));
	assert(equal(Power(2, -3), 0.125));
	assert(equal(Power(2, 0), 1));
	assert(equal(Power(0, 0), 0));
	assert(equal(Power(0, 4), 0));
	assert(equal(Power(0, -4), 0));

	return 0;
}
