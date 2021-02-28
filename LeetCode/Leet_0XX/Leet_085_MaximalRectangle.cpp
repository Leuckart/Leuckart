/**************************************************
	> File Name:  Leet_085_MaximalRectangle.cpp
	> Author:     Leuckart
	> Time:       2019-07-25 02:32
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximalRectangle(const vector<vector<char>> &matrix)
	{
		if (matrix.empty())
			return 0;
		const int row = matrix.size();
		const int col = matrix[0].size();

		vector<int> DP_Height(col, 0);
		vector<int> DP_Left(col, 0);
		vector<int> DP_Right(col, col);

		int max_area = 0;
		for (int i = 0; i < row; ++i)
		{
			// compute height (can do this from either side)
			for (int j = 0; j < col; ++j)
			{
				if (matrix[i][j] == '1')
					DP_Height[j]++;
				else
					DP_Height[j] = 0;
			}

			// compute left (from left to right)
			for (int j = 0, cur_left = 0; j < col; ++j)
			{
				if (matrix[i][j] == '1')
					DP_Left[j] = max(DP_Left[j], cur_left);
				else
				{
					DP_Left[j] = 0;
					cur_left = j + 1;
				}
			}

			// compute right (from right to left)
			for (int j = col - 1, cur_right = col; j >= 0; --j)
			{
				if (matrix[i][j] == '1')
					DP_Right[j] = min(DP_Right[j], cur_right);
				else
				{
					DP_Right[j] = col;
					cur_right = j;
				}
			}

			// compute the area of rectangle (can do this from either side)
			for (int j = 0; j < col; ++j)
				max_area = max(max_area, (DP_Right[j] - DP_Left[j]) * DP_Height[j]);
		}
		return max_area;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
