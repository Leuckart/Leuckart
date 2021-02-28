/**************************************************
	> File Name:  Sword_38_StringPermutation.cpp
	> Author:     Leuckart
	> Time:       2020-02-19 15:46
**************************************************/

// 面试题38：字符串的排列
// 题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
// 则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Permute_Recursive(string &str, int idx, vector<string> &vec)
{
	if (idx == str.length() - 1)
	{
		vec.push_back(str);
		return;
	}

	for (int i = idx; i < str.length(); ++i)
	{
		char tmp = str[idx];
		str[idx] = str[i];
		str[i] = tmp;

		Permute_Recursive(str, idx + 1, vec);

		tmp = str[idx];
		str[idx] = str[i];
		str[i] = tmp;
	}
}

vector<string> Permute(string str)
{
	if (str.empty())
		return {};

	vector<string> ans;
	Permute_Recursive(str, 0, ans);
	return ans;
}

// ====================测试代码====================
void Test(char *pStr)
{
	if (pStr == nullptr)
		printf("Test for nullptr begins:\n");
	else
		printf("Test for %s begins:\n", pStr);

	vector<string> ans = Permute(pStr);
	for (string it : ans)
		cout << it << "\t";

	printf("\n");
}

int main(int argc, char *argv[])
{
	char string1[] = "";
	Test(string1);

	char string2[] = "a";
	Test(string2);

	char string3[] = "ab";
	Test(string3);

	char string4[] = "abc";
	Test(string4);

	return 0;
}
