/**************************************************
	> File Name:  Sword_43_NumberOf1.cpp
	> Author:     Leuckart
	> Time:       2020-02-26 00:13
**************************************************/

// 面试题43：从1到n整数中1出现的次数
// 题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
// 输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。

#include <iostream>
#include <cassert>
using namespace std;

int GetPow(int exp)
{
	int result = 1;
	while (exp-- > 0)
		result *= 10;
	return result;
}

int NumberOf1(int number)
{
	if (number <= 0)
		return 0;

	int bitNum = 0;
	for (int _number = number; _number > 0; _number /= 10)
		++bitNum;

	int Ans = 0;
	int pow = GetPow(bitNum - 1);

	if (number / pow == 1)
		Ans += number % pow + 1;
	else
		Ans += pow;

	Ans += (number / pow) * NumberOf1(pow - 1) + NumberOf1(number % pow);
	return Ans;
}

int main(int argc, char *argv[])
{
	assert(NumberOf1(0) == 0);
	assert(NumberOf1(1) == 1);
	assert(NumberOf1(5) == 1);
	assert(NumberOf1(10) == 2);
	assert(NumberOf1(55) == 16);
	assert(NumberOf1(99) == 20);
	assert(NumberOf1(10000) == 4001);
	assert(NumberOf1(21345) == 18821);

	return 0;
}
