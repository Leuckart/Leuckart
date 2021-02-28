/**************************************************
	> File Name:  Sword_05_ReplaceSpaces.cpp
	> Author:     Leuckart
	> Time:       2020-02-14 17:28
**************************************************/

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include <iostream>
#include <string>
using namespace std;

void ReplaceBlank(string &str)
{
	if (str.empty())
		return;

	int num_blank = 0;
	for (size_t i = 0; i < str.length(); ++i)
		if (str[i] == ' ')
			++num_blank;
	int lhs = str.length();
	int rhs = str.length() + num_blank * 2;

	str.resize(rhs);
	while (--lhs >= 0)
	{
		if (str[lhs] == ' ')
		{
			str[--rhs] = '0';
			str[--rhs] = '2';
			str[--rhs] = '%';
		}
		else
		{
			str[--rhs] = str[lhs];
		}
	}
	cout << str << endl;
}

int main(int argc, char *argv[])
{
	string str1("hello world"),
		str2(" helloworld"),
		str3("helloworld "),
		str4("hello  world"),
		str5("helloworld"),
		str6("   "),
		str7(" "),
		str8("");

	ReplaceBlank(str1);
	ReplaceBlank(str2);
	ReplaceBlank(str3);
	ReplaceBlank(str4);
	ReplaceBlank(str5);
	ReplaceBlank(str6);
	ReplaceBlank(str7);
	ReplaceBlank(str8);

	return 0;
}
