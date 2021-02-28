/**************************************************
	> File Name:  Leet_064_MinimumPathSum.cpp
	> Author:     Leuckart
	> Time:       2019-07-21 16:11
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int minPathSum(const vector<vector<int>> &grid)
	{
		const int row = grid.size();
		const int col = grid[0].size();

		vector<int> DP(col, 0);
		DP[0] = grid[0][0];
		for (int i = 1; i < col; ++i)
			DP[i] = DP[i - 1] + grid[0][i];

		for (int iter = 1; iter < row; ++iter)
		{
			DP[0] += grid[iter][0];
			for (int i = 1; i < col; ++i)
				DP[i] = grid[iter][i] + min(DP[i - 1], DP[i]);
		}
		return DP.back();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
