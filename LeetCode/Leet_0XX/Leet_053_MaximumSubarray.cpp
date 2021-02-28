/**************************************************
	> File Name:  Leet_053_MaximumSubarray.cpp
	> Author:     Leuckart
	> Time:       2019-07-02 15:48
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSubArray(const vector<int> &nums)
	{
		vector<int> DP(nums.size(), 0);
		DP[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i)
			DP[i] = nums[i] + (DP[i - 1] > 0 ? DP[i - 1] : 0);

		return *max_element(DP.cbegin(), DP.cend());
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
