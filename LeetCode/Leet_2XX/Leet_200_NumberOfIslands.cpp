/**************************************************
	> File Name:  Leet_200_NumberOfIslands.cpp
	> Author:     Leuckart
	> Time:       2020-09-18 03:08
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int numIslands(vector<vector<char>> &grid)
	{
		int count = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == '1')
				{
					numIslandsCore(grid, i, j);
					++count;
				}
			}
		}
		return count;
	}

private:
	void numIslandsCore(vector<vector<char>> &grid, int row, int col)
	{
		if (row < 0 || row >= grid.size() ||
			col < 0 || col >= grid[0].size() ||
			grid[row][col] != '1')
			return;

		grid[row][col] = '2';
		numIslandsCore(grid, row - 1, col);
		numIslandsCore(grid, row + 1, col);
		numIslandsCore(grid, row, col - 1);
		numIslandsCore(grid, row, col + 1);
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
