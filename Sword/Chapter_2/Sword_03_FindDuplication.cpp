/**************************************************
	> File Name:  Sword_03_FindDuplication.cpp
	> Author:     Leuckart
	> Time:       2020-02-13 22:55
**************************************************/

// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

#include <iostream>
#include <vector>
using namespace std;

int duplicate(vector<int> vec)
{
	if (vec.empty())
		return -1;

	for (size_t i = 0; i < vec.size(); ++i)
	{
		if (vec[i] < 0 || vec[i] >= vec.size())
			return -1;
	}

	for (size_t i = 0; i < vec.size(); ++i)
	{
		while (vec[i] != i)
		{
			if (vec[i] == vec[vec[i]])
				return vec[i];

			int tmp = vec[i];
			vec[i] = vec[tmp];
			vec[tmp] = tmp;
		}
	}
	return -1;
}

int main()
{
	cout << duplicate({2, 1, 3, 1, 4}) << endl;
	cout << duplicate({2, 4, 3, 1, 4}) << endl;
	cout << duplicate({2, 4, 2, 1, 4}) << endl;
	cout << duplicate({2, 1, 3, 0, 4}) << endl;
	cout << duplicate({2, 1, 3, 5, 4}) << endl;
	cout << duplicate({}) << endl;

	return 0;
}
