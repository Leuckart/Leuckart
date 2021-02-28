/**************************************************
        > File Name:  Leet_130_SurroundedRegions.cpp
        > Author:     Leuckart
        > Time:       2020-04-17 21:30
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void solve(vector<vector<char>> &board)
	{
		if (board.empty())
			return;

		for (int i = 0; i < board[0].size(); ++i)
			solveCore(board, 0, i);
		for (int i = 1; i < board.size(); ++i)
			solveCore(board, i, board[0].size() - 1);
		for (int i = board[0].size() - 2; i >= 0; --i)
			solveCore(board, board.size() - 1, i);
		for (int i = board.size() - 2; i > 0; --i)
			solveCore(board, i, 0);

		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == 'I')
					board[i][j] = 'O';
			}
		}
	}

private:
	void solveCore(vector<vector<char>> &board, const int row, const int col)
	{
		if (row < 0 || row >= board.size() ||
			col < 0 || col >= board[0].size() ||
			board[row][col] != 'O')
			return;

		board[row][col] = 'I';
		solveCore(board, row + 1, col);
		solveCore(board, row - 1, col);
		solveCore(board, row, col + 1);
		solveCore(board, row, col - 1);
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
