/**************************************************
	> File Name:  Sword_47_MaxValueOfGifts.cpp
	> Author:     Leuckart
	> Time:       2020-02-24 01:27
**************************************************/

// 面试题47：礼物的最大价值
// 题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
// （价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或
// 者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
// 算你最多能拿到多少价值的礼物？

#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int GetMaxValue(const vector<vector<int>> &value)
{
	if (value.empty() || value[0].empty())
		return 0;

	const int row = value.size();
	const int col = value[0].size();

	vector<int> table(value[0]);
	for (size_t i = 1; i < table.size(); ++i)
		table[i] += table[i - 1];

	for (size_t i = 1; i < row; ++i)
	{
		for (size_t j = 0; j < col; ++j)
		{
			if (j == 0)
				table[j] += value[i][j];
			else
				table[j] = max(table[j - 1], table[j]) + value[i][j];
		}
	}
	return table[col - 1];
}

int main(int argc, char *argv[])
{
	const vector<vector<int>> value1 = {{1, 2, 3},
										{4, 5, 6},
										{7, 8, 9}};
	assert(GetMaxValue(value1) == 29);

	const vector<vector<int>> value2 = {{1, 10, 3, 8},
										{12, 2, 9, 6},
										{5, 7, 4, 11},
										{3, 7, 16, 5}};
	assert(GetMaxValue(value2) == 53);

	const vector<vector<int>> value3 = {{1, 10, 3, 8}};
	assert(GetMaxValue(value3) == 22);

	const vector<vector<int>> value4 = {{1},
										{12},
										{5},
										{3}};
	assert(GetMaxValue(value4) == 21);

	const vector<vector<int>> value5 = {{3}};
	assert(GetMaxValue(value5) == 3);

	return 0;
}
