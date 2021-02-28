/**************************************************
	> File Name:  Leet_059_SpiralMatrix2.cpp
	> Author:     Leuckart
	> Time:       2019-07-17 21:07
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		int bound_lhs = 0;
		int bound_rhs = n - 1;
		int bound_top = 0;
		int bound_bot = n - 1;
		vector<vector<int>> result(n, vector<int>(n, 0));

		int feed = 1;
		while (bound_lhs <= bound_rhs && bound_top <= bound_bot)
		{
			for (int i = bound_lhs; i <= bound_rhs; ++i)
				result[bound_top][i] = feed++;
			for (int i = bound_top + 1; i <= bound_bot; ++i)
				result[i][bound_rhs] = feed++;

			if (bound_lhs == bound_rhs || bound_top == bound_bot)
				break;

			for (int i = bound_rhs - 1; i >= bound_lhs; --i)
				result[bound_bot][i] = feed++;
			for (int i = bound_bot - 1; i > bound_top; --i)
				result[i][bound_lhs] = feed++;

			++bound_lhs;
			--bound_rhs;
			++bound_top;
			--bound_bot;
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
