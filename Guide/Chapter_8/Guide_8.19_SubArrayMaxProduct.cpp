/**************************************************
	> File Name:  Guide_8.19_SubArrayMaxProduct.cpp
	> Author:     Leuckart
	> Time:       2020-10-19 19:53
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static double maxProduct(const vector<double> &data)
	{
		double cur_max = data[0];
		double cur_min = data[0];
		double result = data[0];

		for (int i = 1; i < data.size(); ++i)
		{
			double prev_max = cur_max;
			double prev_min = cur_min;
			cur_max = max(data[i], max(prev_max * data[i], prev_min * data[i]));
			cur_min = min(data[i], min(prev_max * data[i], prev_min * data[i]));
			result = max(result, cur_max);
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution::maxProduct({-2.5, 4, 0, 3, 0.5, 8, -1});
	return 0;
}
