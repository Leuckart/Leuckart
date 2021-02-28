/**************************************************
	> File Name:  Sword_57_1_TwoNumbersWithSum.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 11:44
**************************************************/

// 面试题57（一）：和为s的两个数字
// 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
// 的和正好是s。如果有多对数字的和等于s，输出任意一对即可。

#include <cassert>
#include <vector>
using namespace std;

bool FindNumbersWithSum(const vector<int> &data, int sum, int &num1, int &num2)
{
	if (data.empty())
		return false;

	for (int lhs = 0, rhs = data.size() - 1; lhs < rhs;)
	{
		int cur_sum = data[lhs] + data[rhs];
		if (cur_sum == sum)
		{
			num1 = data[lhs];
			num2 = data[rhs];
			return true;
		}
		else if (cur_sum < sum)
			++lhs;
		else
			--rhs;
	}
	return false;
}

int main(int argc, char *argv[])
{
	int num1 = 0, num2 = 0;

	assert(FindNumbersWithSum({1, 2, 4, 7, 11, 15}, 15, num1, num2) == true);
	assert(FindNumbersWithSum({1, 2, 4, 7, 11, 16}, 17, num1, num2) == true);
	assert(FindNumbersWithSum({1, 2, 4, 7, 11, 16}, 10, num1, num2) == false);

	return 0;
}
