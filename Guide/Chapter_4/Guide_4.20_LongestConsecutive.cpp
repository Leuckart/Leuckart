/**************************************************
	> File Name:  Guide_4.20_LongestConsecutive.cpp
	> Author:     Leuckart
	> Time:       2020-10-08 23:06
**************************************************/

#include <unordered_set>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int longestConsecutive(const vector<int> &nums)
	{
		unordered_set<int> S(nums.cbegin(), nums.cend());

		int max_len = 0;
		for (unordered_set<int>::const_iterator iter = S.cbegin(); iter != S.cend(); ++iter)
		{
			// 只考虑 num 处于连续子序列最左端的情况
			if (S.find(*iter - 1) != S.cend())
				continue;

			int cur_len = 1;
			for (int i = *iter + 1; S.find(i) != S.cend(); ++i)
				++cur_len;
			max_len = max(max_len, cur_len);
		}
		return max_len;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::longestConsecutive({100, 4, 200, 1, 3, 2}) == 4);
	return 0;
}
