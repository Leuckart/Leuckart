/**************************************************
	> File Name:  Leet_070_ClimbingStairs.cpp
	> Author:     Leuckart
	> Time:       2019-07-05 14:19
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int climbStairs(int n)
	{
		vector<int> DP(n + 1, 0);
		DP[0] = DP[1] = 1;

		for (int i = 2; i <= n; ++i)
			DP[i] = DP[i - 1] + DP[i - 2];
		return DP.back();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
