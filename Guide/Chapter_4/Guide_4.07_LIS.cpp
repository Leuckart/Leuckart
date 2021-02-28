/**************************************************
	> File Name:  Guide_4.07_LIS.cpp
	> Author:     Leuckart
	> Time:       2020-10-06 09:55
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static vector<int> lis(const vector<int> &data)
	{
		if (data.empty())
			return {};

		vector<int> dp(data.size(), 1);		// dp[i] : 以第i个元素结尾的最大递增子序列长
		vector<int> ascend(data.size(), 0); // ascend[0:ascend_end] : 递增子序列的中间值
		ascend[0] = data[0];

		int ascend_end = 0;
		for (int i = 1; i < data.size(); ++i)
		{
			int l = 0;
			int r = ascend_end;
			while (l <= r)
			{
				int m = (l + r) / 2;
				if (ascend[m] < data[i])
					l = m + 1;
				else
					r = m - 1;
			}

			ascend_end = max(ascend_end, l);
			ascend[l] = data[i];
			dp[i] = l + 1;
		}
		return generateLIS(data, dp);
	}

private:
	// 获得最长递增子序列
	static vector<int> generateLIS(const vector<int> &data, const vector<int> &dp)
	{
		int len = 1;
		int pos = 0;
		for (int i = 1; i < data.size(); ++i)
		{
			if (dp[i] >= len)
			{
				len = dp[i];
				pos = i;
			}
		}

		vector<int> result(len, 0);
		result[--len] = data[pos];
		for (int i = pos; i >= 0; --i)
		{
			if (data[i] < data[pos] && dp[i] == dp[pos] - 1)
			{
				result[--len] = data[i];
				pos = i;
			}
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution::lis({2, 1, 5, 3, 6, 4, 8, 9, 7});
	return 0;
}
