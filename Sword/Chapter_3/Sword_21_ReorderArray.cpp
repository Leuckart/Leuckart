/**************************************************
	> File Name:  Sword_21_ReorderArray.cpp
	> Author:     Leuckart
	> Time:       2020-02-17 23:11
**************************************************/

// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。

#include <iostream>
#include <cassert>
#include <vector>
#include <cstdio>
using namespace std;

void ReorderOddEven(vector<int> vec)
{
	int lhs = 0;
	int rhs = vec.size() - 1;
	while (lhs < rhs)
	{
		while (lhs < vec.size() && vec[lhs] % 2 == 1)
			++lhs;
		while (rhs >= 0 && vec[rhs] % 2 == 0)
			--rhs;

		if (lhs < rhs)
		{
			int tmp = vec[lhs];
			vec[lhs] = vec[rhs];
			vec[rhs] = tmp;
		}
	}

	for (int it : vec)
		cout << it << " ";
	cout << endl;
}

int main(int argc, char *argv[])
{
	ReorderOddEven({1, 2, 3, 4, 5, 6, 7});
	ReorderOddEven({2, 4, 6, 1, 3, 5, 7});
	ReorderOddEven({1, 3, 5, 7, 2, 4, 6});
	ReorderOddEven({1});
	ReorderOddEven({2});
	ReorderOddEven({});

	return 0;
}
