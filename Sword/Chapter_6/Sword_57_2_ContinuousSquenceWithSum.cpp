/**************************************************
	> File Name:  Sword_57_2_ContinuousSquenceWithSum.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 11:44
**************************************************/

// 面试题57（二）：为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
// 4～6和7～8。

#include <iostream>
using namespace std;

void FindContinuousSequence(int sum)
{
	cout << " -- -- -- " << sum << " -- -- --" << endl;
	if (sum < 3)
		return;

	int lhs = 1;
	int rhs = 2;
	int cur_sum = lhs + rhs;

	while (lhs < (sum + 1) / 2)
	{
		if (cur_sum < sum)
		{
			++rhs;
			cur_sum += rhs;
		}
		else if (cur_sum > sum)
		{
			cur_sum -= lhs;
			++lhs;
		}
		else
		{
			for (int i = lhs; i <= rhs; ++i)
				cout << i << "\t";
			cout << endl;

			cur_sum -= lhs;
			++lhs;
			++rhs;
			cur_sum += rhs;
		}
	}
}

int main(int argc, char *argv[])
{
	FindContinuousSequence(1);
	FindContinuousSequence(3);
	FindContinuousSequence(4);
	FindContinuousSequence(9);
	FindContinuousSequence(15);
	FindContinuousSequence(100);

	return 0;
}
