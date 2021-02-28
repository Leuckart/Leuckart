/**************************************************
	> File Name:  Guide_8.17_SubMatrixMaxSum.cpp
	> Author:     Leuckart
	> Time:       2020-10-19 02:58
**************************************************/

#include <iostream>
#include <climits>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int maxSum(const vector<vector<int>> &data)
	{
		if (data.empty() || data[0].empty())
			return 0;

		int max_sum = INT_MIN;
		for (int up = 0; up < data.size(); ++up)
		{
			// 从up行起各行的累加和
			vector<int> sums(data[up].size(), 0);
			for (int i = up; i < data.size(); ++i)
			{
				int cur_sum = 0;
				for (int j = 0; j < data[0].size(); ++j)
				{
					sums[j] += data[i][j];
					cur_sum += sums[j];
					max_sum = max(max_sum, cur_sum);
					if (cur_sum < 0)
						cur_sum = 0;
				}
			}
		}
		return max_sum;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::maxSum({{-90, 48, 78},
							 {64, -40, 64},
							 {-81, -7, 66}}) == 209);
	return 0;
}
