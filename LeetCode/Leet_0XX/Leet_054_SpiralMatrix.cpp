/**************************************************
	> File Name:  Leet_054_SpiralMatrix.cpp
	> Author:     Leuckart
	> Time:       2019-07-16 15:57
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> spiralOrder(const vector<vector<int>> &matrix)
	{
		vector<int> result;
		if (matrix.empty())
			return result;

		int left_bound = 0, right_bound = matrix[0].size() - 1;
		int top_bound = 0, bottom_bound = matrix.size() - 1;

		while (left_bound <= right_bound && top_bound <= bottom_bound)
		{
			for (int col = left_bound; col <= right_bound; col++)
				result.push_back(matrix[top_bound][col]);
			for (int row = top_bound + 1; row <= bottom_bound; row++)
				result.push_back(matrix[row][right_bound]);

			if (left_bound == right_bound || top_bound == bottom_bound)
				break;

			for (int col = right_bound - 1; col >= left_bound; col--)
				result.push_back(matrix[bottom_bound][col]);
			for (int row = bottom_bound - 1; row > top_bound; row--)
				result.push_back(matrix[row][left_bound]);

			left_bound++;
			right_bound--;
			top_bound++;
			bottom_bound--;
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
