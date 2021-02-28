/**************************************************
	> File Name:  Guide_8.01_PrintMatrixSpiralOrder.cpp
	> Author:     Leuckart
	> Time:       2020-10-01 15:04
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static void spiralOrderPrint(const vector<vector<int>> &matrix)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = matrix.size() - 1;
		int y2 = matrix[0].size() - 1;

		while (x1 <= x2 && y1 <= y2)
			printEdge(matrix, x1++, y1++, x2--, y2--);
		cout << endl;
	}

private:
	static void printEdge(const vector<vector<int>> &matrix, const int x1, const int y1, const int x2, const int y2)
	{
		if (x1 == x2)
		{
			for (int i = y1; i <= y2; ++i)
				cout << matrix[x1][i] << " ";
		}
		else if (y1 == y2)
		{
			for (int i = x1; i <= x2; ++i)
				cout << matrix[i][y1] << " ";
		}
		else
		{
			for (int i = y1; i <= y2; ++i)
				cout << matrix[x1][i] << " ";
			for (int i = x1 + 1; i <= x2; ++i)
				cout << matrix[i][y2] << " ";
			for (int i = y2 - 1; i >= y1; --i)
				cout << matrix[x2][i] << " ";
			for (int i = x2 - 1; i > x1; --i)
				cout << matrix[i][y1] << " ";
		}
	}
};

int main(int argc, char *argv[])
{
	const vector<vector<int>> matrix = {{1, 2, 3, 4},
										{5, 6, 7, 8},
										{9, 10, 11, 12},
										{13, 14, 15, 16}};
	Solution::spiralOrderPrint(matrix);
	return 0;
}
