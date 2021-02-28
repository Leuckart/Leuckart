/**************************************************
	> File Name:  Leet_011_ContainerWithMostWater.cpp
	> Author:     Leuckart
	> Time:       2019-06-12 20:09
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxArea(const vector<int> &height)
	{
		int ans = 0;
		for (int lhs = 0, rhs = height.size() - 1; lhs < rhs;)
		{
			ans = max(ans, (rhs - lhs) * min(height[lhs], height[rhs]));
			if (height[lhs] < height[rhs])
				++lhs;
			else
				--rhs;
		}
		return ans;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
