/**************************************************
	> File Name:  Guide_8.10_LongestSumSubArray.cpp
	> Author:     Leuckart
	> Time:       2020-10-15 17:07
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int maxLength(const vector<int> &data, const int target)
	{
		if (data.empty() || target < 0)
			return 0;

		int l = 0;
		int r = 0;
		int sum = data[0];
		int max_len = 0;
		while (r < data.size())
		{
			if (sum == target)
			{
				max_len = max(max_len, r - l + 1);
				sum -= data[l];
				++l;
			}
			else if (sum < target)
			{
				++r;
				if (r < data.size())
					sum += data[r];
			}
			else
			{
				sum -= data[l];
				++l;
			}
		}
		return max_len;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::maxLength({1, 2, 1, 1, 1}, 3) == 3);
	return 0;
}
