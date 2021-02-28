/**************************************************
	> File Name:  Leet_264_UglyNumber2.cpp
	> Author:     Leuckart
	> Time:       2020-04-01 15:51
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int nthUglyNumber(int n)
	{
		vector<int> DP(n + 1, 0);
		DP[1] = 1;

		int pos_2 = 1;
		int pos_3 = 1;
		int pos_5 = 1;
		for (int i = 2; i <= n; ++i)
		{
			DP[i] = min(DP[pos_2] * 2, min(DP[pos_3] * 3, DP[pos_5] * 5));

			while (DP[pos_2] * 2 <= DP[i])
				++pos_2;
			while (DP[pos_3] * 3 <= DP[i])
				++pos_3;
			while (DP[pos_5] * 5 <= DP[i])
				++pos_5;
		}
		return DP[n];
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
