/**************************************************
	> File Name:  Sword_11_MinNumberInRotatedArray.cpp
	> Author:     Leuckart
	> Time:       2020-02-16 16:46
**************************************************/

// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

#include <iostream>
#include <vector>
using namespace std;

int Min(vector<int> vec)
{
	if (vec.empty())
		return -1;

	int lhs = 0;
	int rhs = vec.size() - 1;

	while (lhs < rhs)
	{
		if (vec[lhs] < vec[rhs])
			return vec[lhs];
		else if (vec[lhs] == vec[rhs])
			lhs++;
		else
		{
			int mid = (lhs + rhs) / 2;
			if (mid == lhs)
				return vec[rhs];

			if (vec[mid] > vec[lhs])
				lhs = mid + 1;
			else if (vec[mid] < vec[lhs])
				rhs = mid;
			else
				lhs++;
		}
	}
	return vec[lhs];
}

int main(int argc, char *argv[])
{
	cout << Min({3, 4, 5, 1, 2}) << endl;
	cout << Min({3, 4, 5, 1, 1, 2}) << endl;
	cout << Min({3, 4, 5, 1, 2, 2}) << endl;
	cout << Min({1, 0, 1, 1, 1}) << endl;
	cout << Min({1, 1, 1, 0, 1}) << endl;
	cout << Min({1, 2, 3, 4, 5}) << endl;
	cout << Min({1}) << endl;

	return 0;
}
