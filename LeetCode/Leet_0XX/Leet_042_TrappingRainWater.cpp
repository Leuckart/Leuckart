/**************************************************
	> File Name:  Leet_042_TrappingRainWater.cpp
	> Author:     Leuckart
	> Time:       2019-07-11 17:06
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int trap(const vector<int> &height)
	{
		if (height.empty())
			return 0;
		vector<int> DP_Left(height.size(), 0);
		vector<int> DP_Right(height.size(), 0);

		for (int i = 1; i < height.size(); ++i)
			DP_Left[i] = max(DP_Left[i - 1], height[i - 1]);
		for (int i = height.size() - 2; i >= 0; --i)
			DP_Right[i] = max(DP_Right[i + 1], height[i + 1]);

		int max_water = 0;
		for (int i = 1; i < height.size() - 1; ++i)
		{
			if (DP_Left[i] <= height[i] || DP_Right[i] <= height[i])
				continue;
			max_water += min(DP_Left[i], DP_Right[i]) - height[i];
		}
		return max_water;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
