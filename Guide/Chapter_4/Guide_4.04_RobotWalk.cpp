/**************************************************
	> File Name:  Guide_4.04_RobotWalk.cpp
	> Author:     Leuckart
	> Time:       2020-10-05 12:57
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

class Solution
{
public:
	// N个位置，起始为M，限K步，终止为P
	static int ways(const int N, const int M, const int K, const int P)
	{
		if (N < 2 || K < 1 || M < 1 || M > N || P < 1 || P > N)
			return 0;

		// 从终点逆推
		vector<int> dp(N + 1, 0);
		dp[P] = 1;

		for (int i = 1; i <= K; ++i)
		{
			int lastValue = 0;
			for (int j = 1; j <= N; ++j)
			{
				int lastValueTmp = dp[j];
				if (j == N)
					dp[j] = lastValue;
				else
					dp[j] = lastValue + dp[j + 1];

				dp[j] %= MOD;
				lastValue = lastValueTmp;
			}
		}
		return dp[M];
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::ways(5000, 4548, 5000, 1600) == 602611261);
	return 0;
}
