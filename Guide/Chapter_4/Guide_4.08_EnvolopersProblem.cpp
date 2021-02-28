/**************************************************
	> File Name:  Guide_4.08_EnvolopersProblem.cpp
	> Author:     Leuckart
	> Time:       2020-10-07 13:43
**************************************************/

#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int maxEnvolopes(vector<vector<int>> matrix)
	{
		sort(matrix.begin(), matrix.end(),
			 [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]); });

		// ascend[0:ascend_end] : 递增子序列的中间值
		vector<int> ascend(matrix.size(), 0);
		ascend[0] = matrix[0][1];

		int ascend_end = 0;
		for (int i = 1; i < matrix.size(); ++i)
		{
			int l = 0;
			int r = ascend_end;
			while (l <= r)
			{
				int m = (l + r) / 2;
				if (ascend[m] < matrix[i][1])
					l = m + 1;
				else
					r = m - 1;
			}

			ascend_end = max(ascend_end, l);
			ascend[l] = matrix[i][1];
		}
		return ascend_end + 1;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::maxEnvolopes({{3, 4},
								   {2, 3},
								   {4, 5},
								   {1, 3},
								   {2, 2},
								   {3, 6},
								   {1, 2},
								   {3, 2},
								   {2, 4}}) == 4);
	return 0;
}
