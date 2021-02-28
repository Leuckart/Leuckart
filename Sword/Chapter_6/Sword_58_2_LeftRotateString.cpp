/**************************************************
	> File Name:  Sword_58_2_LeftRotateString.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 14:38
**************************************************/

// 面试题58（二）：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
// 字2，该函数将返回左旋转2位得到的结果"cdefgab"。

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

void Reverse(string &str, int beg, int end)
{
	if (beg >= end)
		return;

	for (int i = beg; i <= (beg + end) / 2; ++i)
	{
		char tmp = str[i];
		str[i] = str[end - i + beg];
		str[end - i + beg] = tmp;
	}
}

string LeftRotateString(string str, int n)
{
	if (str.empty())
		return "";
	n %= str.length();

	Reverse(str, 0, n - 1);
	Reverse(str, n, str.length() - 1);
	Reverse(str, 0, str.length() - 1);
	return str;
}

int main(int argc, char *argv[])
{
	assert(LeftRotateString("abcdefg", 2) == "cdefgab");
	assert(LeftRotateString("abcdefg", 1) == "bcdefga");
	assert(LeftRotateString("abcdefg", 6) == "gabcdef");
	assert(LeftRotateString("abcdefg", 0) == "abcdefg");
	assert(LeftRotateString("abcdefg", 7) == "abcdefg");
	assert(LeftRotateString("", 6) == "");

	return 0;
}
