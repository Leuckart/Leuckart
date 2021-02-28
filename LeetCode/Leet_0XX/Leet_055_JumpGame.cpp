/**************************************************
	> File Name:  Leet_055_JumpGame.cpp
	> Author:     Leuckart
	> Time:       2019-07-16 16:33
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canJump(const vector<int> &nums)
	{
		int pos = 0;
		int cur_max = 0;
		while (cur_max < nums.size() - 1)
		{
			int pre_max = cur_max;
			while (pos <= pre_max)
			{
				cur_max = max(cur_max, pos + nums[pos]);
				++pos;
			}

			if (pre_max == cur_max)
				return false;
		}
		return true;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
