/**************************************************
	> File Name:  Leet_048_RotateImage.cpp
	> Author:     Leuckart
	> Time:       2019-07-15 17:23
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void rotate(vector<vector<int>> &matrix)
	{
		int size = matrix.size();
		for (int x = 0; x < size; ++x)
		{
			if (x >= size / 2)
				break;

			for (int y = x; y < size - x - 1; ++y)
			{
				int tmp1 = matrix[x][y];
				int tmp2 = matrix[y][size - 1 - x];
				int tmp3 = matrix[size - 1 - x][size - 1 - y];

				matrix[x][y] = matrix[size - 1 - y][x];
				matrix[y][size - 1 - x] = tmp1;
				matrix[size - 1 - x][size - 1 - y] = tmp2;
				matrix[size - 1 - y][x] = tmp3;
			}
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
