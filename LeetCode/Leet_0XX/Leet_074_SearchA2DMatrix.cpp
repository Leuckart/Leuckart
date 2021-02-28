/**************************************************
	> File Name:  Leet_074_SearchA2DMatrix.cpp
	> Author:     Leuckart
	> Time:       2019-07-22 16:31
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool searchMatrix(const vector<vector<int>> &matrix, int target)
	{
		if (matrix.empty())
			return false;

		int row = 0;
		int col = matrix[0].size() - 1;
		while (row < matrix.size() && col >= 0)
		{
			if (target < matrix[row][col])
				--col;
			else if (target > matrix[row][col])
				++row;
			else
				return true;
		}
		return false;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
