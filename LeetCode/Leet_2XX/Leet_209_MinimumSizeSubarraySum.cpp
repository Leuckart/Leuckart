/**************************************************
	> File Name:  Leet_209_MinimumSizeSubarraySum.cpp
	> Author:     Leuckart
	> Time:       2020-09-21 17:28
**************************************************/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSubArrayLen(const int s, const vector<int> &nums)
	{
		if (nums.empty())
			return 0;

		int lhs = 0;
		int rhs = 0;
		int cur_sum = nums[0];
		int min_len = INT_MAX;

		while (rhs < nums.size())
		{
			if (cur_sum >= s)
			{
				min_len = min(min_len, rhs - lhs + 1);
				cur_sum -= nums[lhs];
				++lhs;
			}
			else if (rhs < nums.size() - 1)
			{
				++rhs;
				cur_sum += nums[rhs];
			}
			else
				break;
		}
		return min_len == INT_MAX ? 0 : min_len;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	cout << sol.minSubArrayLen(7, {2, 3, 1, 2, 4, 3}) << endl;
	cout << sol.minSubArrayLen(4, {1, 4, 4}) << endl;
	cout << sol.minSubArrayLen(11, {1, 2, 3, 4, 5}) << endl;
	return 0;
}
