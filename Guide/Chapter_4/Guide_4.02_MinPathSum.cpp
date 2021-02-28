/**************************************************
	> File Name:  Guide_4.02_MinPathSum.cpp
	> Author:     Leuckart
	> Time:       2020-10-04 18:37
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int minPathSum(const vector<vector<int>> &matrix)
	{
		if (matrix.empty() || matrix[0].empty())
			return 0;

		vector<int> dp(matrix[0].size(), 0);
		dp[0] = matrix[0][0];

		for (int i = 1; i < dp.size(); ++i)
			dp[i] = dp[i - 1] + matrix[0][i];

		for (int i = 1; i < matrix.size(); ++i)
		{
			dp[0] += matrix[i][0];
			for (int j = 1; j < dp.size(); ++j)
				dp[j] = min(dp[j], dp[j - 1]) + matrix[i][j];
		}
		return dp.back();
	}
};

int main(int argc, char *argv[])
{
	assert(12 == Solution::minPathSum({{1, 3, 5, 9},
									   {8, 1, 3, 4},
									   {5, 0, 6, 1},
									   {8, 8, 4, 0}}));
	return 0;
}
