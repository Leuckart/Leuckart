/**************************************************
	> File Name:  Guide_8.03_ZigZagPrintMatrix.cpp
	> Author:     Leuckart
	> Time:       2020-10-14 16:55
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static void printMatrixZigZag(const vector<vector<int>> &matrix)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;

		bool upFlag = true;
		do
		{
			if (upFlag)
			{
				for (int i = 0; x1 - i >= x2; ++i)
					cout << matrix[x1 - i][y1 + i] << " ";
			}
			else
			{
				for (int i = 0; x2 + i <= x1; ++i)
					cout << matrix[x2 + i][y2 - i] << " ";
			}
			upFlag ^= 1;

			if (x1 < matrix.size() - 1)
				++x1;
			else
				++y1;

			if (y2 < matrix[0].size() - 1)
				++y2;
			else
				++x2;
		} while (y1 != matrix[0].size() && x2 != matrix.size());
		cout << endl;
	}
};

int main(int argc, char *argv[])
{
	Solution::printMatrixZigZag({{1, 2, 3, 4},
								 {5, 6, 7, 8},
								 {9, 10, 11, 12},
								 {13, 14, 15, 16}});
	return 0;
}
