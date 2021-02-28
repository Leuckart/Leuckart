/**************************************************
	> File Name:  Leet_120_Triangle.cpp
	> Author:     Leuckart
	> Time:       2020-04-13 19:53
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumTotal(const vector<vector<int>> &triangle)
	{
		if (triangle.empty())
			return 0;
		vector<int> DP(triangle.size(), 0);
		DP[0] = triangle[0][0];

		for (int i = 1; i < triangle.size(); ++i)
		{
			DP[i] = DP[i - 1] + triangle[i][i];
			for (int j = i - 1; j > 0; --j)
				DP[j] = triangle[i][j] + min(DP[j - 1], DP[j]);
			DP[0] = DP[0] + triangle[i][0];
		}
		return *min_element(DP.cbegin(), DP.cend());
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
