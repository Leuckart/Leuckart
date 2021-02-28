/**************************************************
	> File Name:  Leet_198_HouseRobber.cpp
	> Author:     Leuckart
	> Time:       2020-09-06 16:21
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int rob(const vector<int> &nums)
	{
		vector<int> DP(3, 0);
		for (int i = 0; i < nums.size(); ++i)
		{
			int cur = max(DP[0], DP[1]) + nums[i];
			DP = {DP[1], DP[2], cur};
		}
		return *max_element(DP.cbegin(), DP.cend());
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
