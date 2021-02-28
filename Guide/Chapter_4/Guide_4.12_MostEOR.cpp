/**************************************************
	> File Name:  Guide_4.12_MostEOR.cpp
	> Author:     Leuckart
	> Time:       2020-10-07 19:30
**************************************************/

#include <unordered_map>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int mostEOR(const vector<int> &data)
	{
		if (data.empty())
			return 0;

		// dp[i] : data[0:i]的异或和为0的子数组的最大数目
		vector<int> dp(data.size(), 0);
		dp[0] = data[0] == 0 ? 1 : 0;

		// key : 异或和 ; value : 异或和的位置
		unordered_map<int, int> Mp;
		Mp[0] = -1;
		Mp[data[0]] = 0;

		int eor = data[0];
		for (int i = 1; i < data.size(); ++i)
		{
			eor ^= data[i];
			unordered_map<int, int>::const_iterator iter = Mp.find(eor);
			if (iter != Mp.cend())
				dp[i] = iter->second == -1 ? 1 : (dp[iter->second] + 1);

			dp[i] = max(dp[i], dp[i - 1]);
			Mp[eor] = i;
		}
		return dp.back();
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::mostEOR({3, 2, 1, 9, 0, 7, 0, 2, 1, 3}) == 4);
	return 0;
}
