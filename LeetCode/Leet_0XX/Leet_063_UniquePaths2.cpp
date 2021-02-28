/**************************************************
	> File Name:  Leet_063_UniquePaths2.cpp
	> Author:     Leuckart
	> Time:       2019-07-21 15:40
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int uniquePathsWithObstacles(const vector<vector<int>> &obstacleGrid)
	{
		const int row = obstacleGrid.size();
		const int col = obstacleGrid[0].size();

		vector<long> DP(col, 0);
		DP[0] = obstacleGrid[0][0] == 0;
		for (int iter = 0; iter < row; ++iter)
		{
			if (obstacleGrid[iter][0] == 1)
				DP[0] = 0;
			for (int i = 1; i < col; ++i)
				DP[i] = obstacleGrid[iter][i] ? 0 : DP[i] + DP[i - 1];
		}
		return DP.back();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
