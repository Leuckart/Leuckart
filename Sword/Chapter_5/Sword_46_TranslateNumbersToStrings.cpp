/**************************************************
	> File Name:  Sword_46_TranslateNumbersToStrings.cpp
	> Author:     Leuckart
	> Time:       2020-02-22 21:18
**************************************************/

// 面试题46：把数字翻译成字符串
// 题目：给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻
// 译成"b"，……，11翻译成"l"，……，25翻译成"z"。一个数字可能有多个翻译。例
// 如12258有5种不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和
// "mzi"。请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。

#include <cassert>
#include <string>
using namespace std;

int GetTransCountRecursive(string num, int idx)
{
	if (idx >= num.length() - 1)
		return 1;

	if ((num[idx] == '1') ||
		(num[idx] == '2' && num[idx + 1] < '6'))
		return GetTransCountRecursive(num, idx + 1) + GetTransCountRecursive(num, idx + 2);
	else
		return GetTransCountRecursive(num, idx + 1);
}

int GetTransCount(int number)
{
	if (number < 0)
		return 0;
	if (number < 10)
		return 1;

	return GetTransCountRecursive(to_string(number), 0);
}

int main(int argc, char *argv[])
{
	assert(GetTransCount(0) == 1);
	assert(GetTransCount(10) == 2);
	assert(GetTransCount(125) == 3);
	assert(GetTransCount(126) == 2);
	assert(GetTransCount(426) == 1);
	assert(GetTransCount(100) == 2);
	assert(GetTransCount(101) == 2);
	assert(GetTransCount(12258) == 5);
	assert(GetTransCount(-100) == 0);

	return 0;
}
