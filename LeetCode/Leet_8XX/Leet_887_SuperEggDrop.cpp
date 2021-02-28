/**************************************************
	> File Name:  Leet_887_SuperEggDrop.cpp
	> Author:     Leuckart
	> Time:       2020-04-16 16:06
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int superEggDrop(const int K, const int N)
	{
		vector<vector<int>> DP(N + 1, vector<int>(K + 1, 0));
		int step = 0;
		while (DP[step][K] < N)
		{
			++step;
			for (int i = 1; i <= K; ++i)
				DP[step][i] = 1 + DP[step - 1][i - 1] + DP[step - 1][i];
		}
		return step;
	}

	int superEggDropV2(const int K, const int N)
	{
		vector<int> DP(K + 1, 0);
		int step = 0;

		while (DP.back() < N)
		{
			++step;
			for (int i = K; i > 0; --i)
				DP[i] += 1 + DP[i - 1];
		}
		return step;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
