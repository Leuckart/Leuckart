/**************************************************
	> File Name:  Leet_036_ValidSudoku.cpp
	> Author:     Leuckart
	> Time:       2019-07-05 19:15
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isValidSudoku(vector<vector<char>> &board)
	{
		if (board.empty() || board[0].empty())
			return false;

		bool row_flag[9][9] = {false};
		bool col_flag[9][9] = {false};
		bool grid_flag[9][9] = {false};

		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] != '.')
				{
					int tmp = board[i][j] - '1';
					if (row_flag[i][tmp] || col_flag[j][tmp] || grid_flag[3 * (i / 3) + j / 3][tmp])
						return false;
					row_flag[i][tmp] = true;
					col_flag[j][tmp] = true;
					grid_flag[3 * (i / 3) + j / 3][tmp] = true;
				}
			}
		}
		return true;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
