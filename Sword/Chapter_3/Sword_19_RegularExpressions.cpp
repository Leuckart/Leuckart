/**************************************************
	> File Name:  Sword_19_RegularExpressions.cpp
	> Author:     Leuckart
	> Time:       2020-02-17 16:38
**************************************************/

// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。

#include <iostream>
#include <cassert>
using namespace std;

bool matchRecursive(const char *str, const char *patt)
{
	if (str[0] != '\0' && patt[0] == '\0')
		return false;
	if (str[0] == '\0' && patt[0] == '\0')
		return true;

	if (str[0] == '\0' && patt[0] != '\0')
	{
		if (patt[1] == '*')
			return matchRecursive(str, patt + 2);
		else
			return false;
	}

	if (patt[1] == '*')
	{
		if (patt[0] == str[0] || patt[0] == '.')
		{
			return matchRecursive(str + 1, patt) ||
				   matchRecursive(str + 1, patt + 2) ||
				   matchRecursive(str, patt + 2);
		}
		else
		{
			return matchRecursive(str, patt + 2);
		}
	}
	if (patt[0] == str[0] || patt[0] == '.')
		return matchRecursive(str + 1, patt + 1);

	return false;
}

bool match(const char *str, const char *patt)
{
	if (!str || !patt)
		return false;

	return matchRecursive(str, patt);
}

int main(int argc, char *argv[])
{
	assert(match("", "") == true);
	assert(match("", ".*") == true);
	assert(match("", ".") == false);
	assert(match("", "c*") == true);
	assert(match("a", ".*") == true);

	assert(match("a", "a.") == false);
	assert(match("a", "") == false);
	assert(match("a", ".") == true);
	assert(match("a", "ab*") == true);
	assert(match("a", "ab*a") == false);

	assert(match("aa", "aa") == true);
	assert(match("aa", "a*") == true);
	assert(match("aa", ".*") == true);
	assert(match("aa", ".") == false);
	assert(match("ab", ".*") == true);

	assert(match("ab", ".*") == true);
	assert(match("aaa", "aa*") == true);
	assert(match("aaa", "aa.a") == false);
	assert(match("aaa", "a.a") == true);
	assert(match("aaa", ".a") == false);

	assert(match("aaa", "a*a") == true);
	assert(match("aaa", "ab*a") == false);
	assert(match("aaa", "ab*ac*a") == true);
	assert(match("aaa", "ab*a*c*a") == true);
	assert(match("aaa", ".*") == true);

	assert(match("aab", "c*a*b") == true);
	assert(match("aaca", "ab*a*c*a") == true);
	assert(match("aaba", "ab*a*c*a") == false);
	assert(match("bbbba", ".*a*a") == true);
	assert(match("bcbbabab", ".*a*a") == false);

	return 0;
}
