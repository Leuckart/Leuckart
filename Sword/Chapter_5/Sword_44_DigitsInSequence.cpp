/**************************************************
	> File Name:  Sword_44_DigitsInSequence.cpp
	> Author:     Leuckart
	> Time:       2020-02-23 15:05
**************************************************/

// 面试题44：数字序列中某一位的数字
// 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
// 个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一
// 个函数求任意位对应的数字。

#include <iostream>
#include <cassert>
using namespace std;

int getPow(int n)
{
	int ans = 1;
	while (n-- > 0)
		ans *= 10;
	return ans;
}

int getDigit(int index)
{
	int bit = 1;
	while (index > 0)
	{
		if (index > 9 * bit * getPow(bit - 1))
		{
			index -= 9 * bit * getPow(bit - 1);
			++bit;
		}
		else
			break;
	}

	int num = getPow(bit - 1) + (index - 1) / bit;
	int res = (index - 1) % bit;

	return (num / getPow(bit - 1 - res)) % 10;
}

int main()
{
	assert(getDigit(0) == 0);
	assert(getDigit(1) == 1);
	assert(getDigit(9) == 9);
	assert(getDigit(10) == 1);
	assert(getDigit(189) == 9);
	assert(getDigit(190) == 1);
	assert(getDigit(1000) == 3);
	assert(getDigit(1001) == 7);
	assert(getDigit(1002) == 0);

	return 0;
}
