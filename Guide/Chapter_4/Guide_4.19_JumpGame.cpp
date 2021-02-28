/**************************************************
	> File Name:  Guide_4.19_JumpGame.cpp
	> Author:     Leuckart
	> Time:       2020-10-08 22:42
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int jump(const vector<int> &data)
	{
		if (data.empty())
			return 0;

		int slow = 0;
		int fast = 0;
		int step = 0;

		while (fast < data.size() - 1)
		{
			int fast_cp = fast;
			for (int i = slow; i <= fast; ++i)
				fast_cp = max(fast_cp, i + data[i]);

			slow = fast + 1;
			fast = fast_cp;
			++step;
		}
		return step;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::jump({3, 2, 3, 1, 1, 4}) == 2);
	return 0;
}
