/**************************************************
	> File Name:  Guide_8.12_LongestLessSumSubArray.cpp
	> Author:     Leuckart
	> Time:       2020-10-17 17:02
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
		if (data.empty())
			return 0;

		vector<int> min_sum(data.size(), 0);	 // 以data[i]起始的最小累加和
		vector<int> min_sum_end(data.size(), 0); // 以data[i]起始的最小累加和的右边界
		min_sum[data.size() - 1] = data.back();
		min_sum_end[data.size() - 1] = data.size() - 1;

		for (int i = data.size() - 2; i >= 0; --i)
		{
			if (min_sum[i + 1] < 0)
			{
				min_sum[i] = data[i] + min_sum[i + 1];
				min_sum_end[i] = min_sum_end[i + 1];
			}
			else
			{
				min_sum[i] = data[i];
				min_sum_end[i] = i;
			}
		}

		int max_len = 0;
		// l为窗口左边界，r-1为窗口右边界
		for (int l = 0, r = 0, sum = 0; l < data.size(); ++l)
		{
			while (r < data.size() && sum + min_sum[r] <= target)
			{
				sum += min_sum[r];
				r = min_sum_end[r] + 1;
			}
			max_len = max(max_len, r - l);

			if (r > l)
				sum -= data[l];
			else
				r = l + 1;
		}
		return max_len;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::maxLength({3, -2, -4, 0, 6}, -2) == 4);
	return 0;
}
