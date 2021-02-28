/**************************************************
	> File Name:  Sword_17_Print1ToMaxOfNDigits.cpp
	> Author:     Leuckart
	> Time:       2020-02-17 13:01
**************************************************/

// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

#include <iostream>
#include <string>
using namespace std;

void Print(const string &num)
{
	size_t idx = 0;
	while (idx < num.length() && num[idx] == '0')
		++idx;

	if (idx == num.length())
		cout << "0 ";
	else
		cout << num.substr(idx) << " ";
}

void Increment(string &num)
{
	num[num.length() - 1] += 1;
	for (int idx = num.length() - 1; num[idx] > '9'; --idx)
	{
		num[idx] -= 10;
		num[idx - 1] += 1;
	}
}

void PrintToMaxNDigits(int n)
{
	if (n < 1)
		return;

	string num(n + 1, '0');
	while (num[0] == '0')
	{
		Print(num);
		Increment(num);
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
	PrintToMaxNDigits(1);
	PrintToMaxNDigits(2);
	PrintToMaxNDigits(3);
	PrintToMaxNDigits(0);
	PrintToMaxNDigits(-1);

	return 0;
}
