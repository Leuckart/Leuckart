/**************************************************
	> File Name:  Leet_062_UniquePaths.cpp
	> Author:     Leuckart
	> Time:       2019-07-21 12:09
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		if (m == 0 || n == 0)
			return 0;

		vector<long> DP(n, 0);
		DP[0] = 1;

		for (int iter = 0; iter < m; ++iter)
			for (int i = 1; i < n; ++i)
				DP[i] += DP[i - 1];
		return DP.back();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
