/**************************************************
	> File Name:  Leet_1246_PalindromeRemoval.cpp
	> Author:     Leuckart
	> Time:       2020-04-01 15:57
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumMoves(vector<int> &arr)
	{
		vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
		for (int i = 0; i < arr.size(); i++)
			dp[i][i] = 1;
		for (int i = 0; i < arr.size() - 1; i++)
			dp[i][i + 1] = arr[i] == arr[i + 1] ? 1 : 2;

		for (int len = 2; len < arr.size(); len++)
		{
			for (int i = 0; i < arr.size() - len; i++)
			{
				dp[i][i + len] = len + 1;
				for (int k = 0; k < len; k++)
					if (dp[i][i + len] > dp[i][i + k] + dp[i + k + 1][i + len])
						dp[i][i + len] = dp[i][i + k] + dp[i + k + 1][i + len];

				if (arr[i] == arr[i + len] && dp[i][i + len] > dp[i + 1][i + len - 1])
					dp[i][i + len] = dp[i + 1][i + len - 1];
			}
		}
		return dp[0].back();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
