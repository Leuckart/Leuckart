/**************************************************
	> File Name:  Sword_03_FindDuplication2.cpp
	> Author:     Leuckart
	> Time:       2020-02-14 13:09
**************************************************/

// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的输出是重复的数字2或者3。

#include <vector>
#include <iostream>
using namespace std;

int countRange(const vector<int> &vec, int beg, int end)
{
	if (vec.empty())
		return 0;

	int count = 0;
	for (size_t i = 0; i < vec.size(); ++i)
		if (vec[i] >= beg && vec[i] <= end)
			++count;
	return count;
}

int getDuplication(const vector<int> vec)
{
	if (vec.empty())
		return -1;

	for (int beg = 1, end = vec.size() - 1; beg <= end;)
	{
		int mid = ((end - beg) >> 1) + beg;
		int count = countRange(vec, beg, mid);
		if (beg == end)
		{
			if (count > 1)
				return beg;
			else
				break;
		}

		if (count > (mid - beg + 1))
			end = mid;
		else
			beg = mid + 1;
	}
	return -1;
}

int main()
{
	cout << getDuplication({2, 3, 5, 4, 3, 2, 6, 7}) << endl;
	cout << getDuplication({3, 2, 1, 4, 4, 5, 6, 7}) << endl;
	cout << getDuplication({1, 2, 3, 4, 5, 6, 7, 1, 8}) << endl;
	cout << getDuplication({1, 7, 3, 4, 5, 6, 8, 2, 8}) << endl;
	cout << getDuplication({1, 1}) << endl;
	cout << getDuplication({3, 2, 1, 3, 4, 5, 6, 7}) << endl;
	cout << getDuplication({1, 2, 2, 6, 4, 5, 6}) << endl;
	cout << getDuplication({1, 2, 2, 6, 4, 5, 2}) << endl;
	cout << getDuplication({1, 2, 6, 4, 5, 3}) << endl;
	cout << getDuplication({}) << endl;

	return 0;
}
