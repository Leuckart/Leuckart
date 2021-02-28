/**************************************************
	> File Name:  Sword_29_PrintMatrix.cpp
	> Author:     Leuckart
	> Time:       2020-02-18 12:03
**************************************************/

// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

#include <iostream>
#include <vector>
using namespace std;

void PrintMatrix(vector<vector<int>> mat)
{
	if (mat.empty() || mat[0].empty())
		return;

	int row = mat.size();
	int col = mat[0].size();
	for (int r = 0, c = 0; r <= (row - 1) / 2 && c <= (col - 1) / 2; ++r, ++c)
	{
		int r_beg = r;
		int r_end = row - r - 1;
		int c_beg = c;
		int c_end = col - c - 1;

		for (int i = c_beg; i <= c_end; ++i)
			cout << mat[r_beg][i] << "\t";

		for (int i = r_beg + 1; i <= r_end; ++i)
			cout << mat[i][c_end] << "\t";

		if (r_beg != r_end)
			for (int i = c_end - 1; i >= c_beg; --i)
				cout << mat[r_end][i] << "\t";

		if (c_beg != c_end)
			for (int i = r_end - 1; i > r_beg; --i)
				cout << mat[i][c_beg] << "\t";
	}
	cout << endl;
}

// ====================测试代码====================
void Test(int rows, int columns)
{
	cout << "Test Begin: " << rows << "x" << columns << endl;
	if (columns < 1 || rows < 1)
		return;

	vector<vector<int>> mat(rows, vector<int>(columns, 0));
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < columns; ++j)
			mat[i][j] = i * columns + j + 1;
	PrintMatrix(mat);
}

int main(int argc, char *argv[])
{
	/*
    1    
    */
	Test(1, 1);

	/*
    1    2
    3    4
    */
	Test(2, 2);

	/*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
	Test(4, 4);

	/*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
	Test(5, 5);

	/*
    1
    2
    3
    4
    5
    */
	Test(5, 1);

	/*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
	Test(5, 2);

	/*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
	Test(5, 3);

	/*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
	Test(5, 4);

	/*
    1    2    3    4    5
    */
	Test(1, 5);

	/*
    1    2    3    4    5
    6    7    8    9    10
    */
	Test(2, 5);

	/*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
	Test(3, 5);

	/*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
	Test(4, 5);

	return 0;
}
