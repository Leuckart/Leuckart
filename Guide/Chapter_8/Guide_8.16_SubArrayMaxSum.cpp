/**************************************************
	> File Name:  Guide_8.16_SubArrayMaxSum.cpp
	> Author:     Leuckart
	> Time:       2020-10-19 02:48
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int maxSum(const vector<int> &data)
	{
		if (data.empty())
			return 0;

		int max_sum = data[0];
		int cur_sum = data[0];
		for (int i = 1; i < data.size(); ++i)
		{
			if (cur_sum > 0)
				cur_sum += data[i];
			else
				cur_sum = data[i];
			max_sum = max(max_sum, cur_sum);
		}
		return max_sum;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::maxSum({-2, -3, -5, -1}) == -1);
	assert(Solution::maxSum({-2, -3, -5, 0, 1, 2, -1}) == 3);
	assert(Solution::maxSum({-2, -3, -5, 40, -10, -10, 100, 1}) == 121);
	return 0;
}
