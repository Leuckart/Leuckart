/**************************************************
	> File Name:  Leet_240_SearchA2DMatrix2.cpp
	> Author:     Leuckart
	> Time:       2020-09-23 20:42
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool searchMatrix(const vector<vector<int>> &matrix, const int target)
	{
		if (matrix.empty() || matrix[0].empty())
			return false;

		for (int i = 0, j = matrix[0].size() - 1; i < matrix.size() && j >= 0;)
		{
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] < target)
				++i;
			else
				--j;
		}
		return false;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
