/**************************************************
	> File Name:  Leet_084_LargestRectangleInHistogram.cpp
	> Author:     Leuckart
	> Time:       2019-07-24 17:12
**************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
	int largestRectangleArea(vector<int> &heights)
	{
		int area = 0;
		heights.push_back(0);
		// 递增序列
		stack<int> S;

		for (int i = 0; i < heights.size(); ++i)
		{
			// 不断将柱子序号放进栈中，直到遇到相邻柱子呈下降关系
			while (!S.empty() && heights[S.top()] > heights[i])
			{
				int Hei = heights[S.top()];
				S.pop();
				int Wid = S.empty() ? i : i - 1 - S.top();
				area = max(area, Hei * Wid);
			}
			S.push(i);
		}
		return area;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
