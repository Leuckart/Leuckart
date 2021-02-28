/**************************************************
	> File Name:  Sword_58_1_ReverseWordsInSentence.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 13:39
**************************************************/

// 面试题58（一）：翻转单词顺序
// 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
// 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
// 则输出"student. a am I"。

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

bool beChar(char ch)
{
	return (ch >= 'A' && ch <= 'Z') ||
		   (ch >= 'a' && ch <= 'z') ||
		   ch == ',' ||
		   ch == '.';
}

string ReverseSentence(const string &str)
{
	if (str.empty())
		return "";

	string rev = str;
	int lhs = str.length() - 1;
	int rhs = str.length() - 1;
	int pos = 0;
	while (lhs >= 0 && rhs >= 0)
	{
		while (rhs >= 0 && !beChar(str[rhs]))
			--rhs;

		lhs = rhs;
		while (lhs >= 0 && beChar(str[lhs]))
			--lhs;

		for (size_t i = lhs + 1; i <= rhs; ++i)
		{
			rev[pos++] = str[i];
		}

		if (lhs >= 0)
			rev[pos++] = ' ';
		rhs = lhs - 1;
	}

	return rev;
}

int main(int argc, char *argv[])
{
	assert(ReverseSentence("I am a student.") == "student. a am I");
	assert(ReverseSentence("Wonderful") == "Wonderful");
	assert(ReverseSentence("") == "");

	return 0;
}
