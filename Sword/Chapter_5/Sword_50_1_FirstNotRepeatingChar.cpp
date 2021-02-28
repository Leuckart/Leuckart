/**************************************************
	> File Name:  Sword_50_1_FirstNotRepeatingChar.cpp
	> Author:     Leuckart
	> Time:       2020-02-26 17:32
**************************************************/

// 面试题50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出
// 'b'。

#include <cassert>
#include <string>
#include <vector>
using namespace std;

char FirstNotRepeatChar(const string &str)
{
	vector<int> alphabet(256, 0);
	for (size_t i = 0; i < str.length(); ++i)
		alphabet[str[i] - '\0'] += 1;

	for (size_t i = 0; i < str.length(); ++i)
		if (alphabet[str[i] - '\0'] == 1)
			return str[i];
	return '\0';
}

int main(int argc, char *argv[])
{
	assert(FirstNotRepeatChar("google") == 'l');
	assert(FirstNotRepeatChar("abcdefg") == 'a');
	assert(FirstNotRepeatChar("aabccdbd") == '\0');
	assert(FirstNotRepeatChar("") == '\0');

	return 0;
}
