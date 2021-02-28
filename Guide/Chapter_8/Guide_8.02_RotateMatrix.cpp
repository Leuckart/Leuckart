/**************************************************
	> File Name:  Guide_8.02_RotateMatrix.cpp
	> Author:     Leuckart
	> Time:       2020-10-13 23:01
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static void rotate(vector<vector<int>> &matrix)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = matrix.size() - 1;
		int y2 = matrix[0].size() - 1;

		while (x1 < x2)
			rotateEdge(matrix, x1++, y1++, x2--, y2--);
	}

private:
	static void rotateEdge(vector<vector<int>> &matrix, const int x1, const int y1, const int x2, const int y2)
	{
		for (int i = 0; i < (y2 - y1); ++i)
		{
			int cur = matrix[x1][y1 + i];
			matrix[x1][y1 + i] = matrix[x2 - i][y1];
			matrix[x2 - i][y1] = matrix[x2][y2 - i];
			matrix[x2][y2 - i] = matrix[x1 + i][y2];
			matrix[x1 + i][y2] = cur;
		}
	}
};

int main(int argc, char *argv[])
{
	vector<vector<int>> matrix = {{1, 2, 3, 4},
								  {5, 6, 7, 8},
								  {9, 10, 11, 12},
								  {13, 14, 15, 16}};
	Solution::rotate(matrix);
	return 0;
}
