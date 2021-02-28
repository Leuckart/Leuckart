/**************************************************
	> File Name:  Sword_04_FindInPartiallySortedMatrix.cpp
	> Author:     Leuckart
	> Time:       2020-02-14 16:08
**************************************************/

// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

#include <iostream>
#include <vector>
using namespace std;

bool Find(const vector<int> vec, const int row, const int col, const int targ)
{
	if (vec.empty() || row < 0 || col < 0)
		return false;

	for (int r = 0, c = col - 1; r < row && c >= 0;)
	{
		if (vec[r * col + c] == targ)
			return true;
		else if (vec[r * col + c] > targ)
			--c;
		else
			++r;
	}
	return false;
}

int main(int argc, char *argv[])
{
	vector<int> vec = {1, 2, 8, 9,
					   2, 4, 9, 12,
					   4, 7, 10, 13,
					   6, 8, 11, 15};

	// Try Assert ?
	cout << Find(vec, 4, 4, 7) << endl;
	cout << Find(vec, 4, 4, 5) << endl;
	cout << Find(vec, 4, 4, 1) << endl;
	cout << Find(vec, 4, 4, 15) << endl;
	cout << Find(vec, 4, 4, 0) << endl;
	cout << Find(vec, 4, 4, 16) << endl;
	cout << Find({}, 0, 0, 16) << endl;

	return 0;
}
