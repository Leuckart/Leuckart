/**************************************************
	> File Name:  Leet_079_WordSearch.cpp
	> Author:     Leuckart
	> Time:       2019-07-23 14:34
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	bool exist(vector<vector<char>> &board, string word)
	{
		if (word.empty())
			return true;
		if (board.empty())
			return false;

		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j)
				if (existCore(board, i, j, word, 0))
					return true;
		return false;
	}

private:
	bool existCore(vector<vector<char>> &board, const int row, const int col,
				   const string &word, int index)
	{
		if (row < 0 || row >= board.size() ||
			col < 0 || col >= board[0].size() ||
			board[row][col] != word[index])
			return false;
		if (index + 1 == word.length())
			return true;

		char ch = board[row][col];
		board[row][col] = '.';
		bool result = existCore(board, row + 1, col, word, index + 1) ||
					  existCore(board, row - 1, col, word, index + 1) ||
					  existCore(board, row, col + 1, word, index + 1) ||
					  existCore(board, row, col - 1, word, index + 1);
		board[row][col] = ch;
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
