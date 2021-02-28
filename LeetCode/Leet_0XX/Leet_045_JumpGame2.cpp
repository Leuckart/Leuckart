/**************************************************
	> File Name:  Leet_045_JumpGame2.cpp
	> Author:     Leuckart
	> Time:       2019-07-15 00:56
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int jump(const vector<int> &nums)
	{
		int times = 0;
		for (int i = 0, cur_max = 0; cur_max < nums.size() - 1; ++times)
		{
			const int pre_max = cur_max;
			// 试图前进
			while (i <= pre_max)
			{
				cur_max = max(cur_max, i + nums[i]);
				++i;
			}

			// 无法前进
			if (pre_max == cur_max)
				return -1;
		}
		return times;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
