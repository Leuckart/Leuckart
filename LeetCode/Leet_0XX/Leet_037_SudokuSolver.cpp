/**************************************************
	> File Name:  Leet_037_SudokuSolver.cpp
	> Author:     Leuckart
	> Time:       2019-07-08 15:07
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void solveSudoku(vector<vector<char>> &board)
	{
		solveSudokuCore(board);
	}

private:
	bool solveSudokuCore(vector<vector<char>> &board)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] == '.')
				{
					for (int feed = 1; feed < 10; ++feed)
					{
						board[i][j] = feed + '0';
						if (isValid(board, i, j) && solveSudokuCore(board))
							return true;
						board[i][j] = '.';
					}
					return false;
				}
			}
		}
		return true;
	}

	bool isValid(const vector<vector<char>> &board, const int row, const int col)
	{
		char key = board[row][col];
		for (int i = 0; i < 9; ++i)
			if (board[row][i] == key && i != col)
				return false;
		for (int i = 0; i < 9; ++i)
			if (board[i][col] == key && i != row)
				return false;
		int grid_x = row / 3;
		int grid_y = col / 3;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (board[3 * grid_x + i][3 * grid_y + j] == key &&
					3 * grid_x + i != row &&
					3 * grid_y + j != col)
					return false;
		return true;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
