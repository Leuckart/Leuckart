/**************************************************
	> File Name:  LeetCode_050_Pow.cpp
	> Author:     Leuckart
	> Time:       2019-06-27 19:43
**************************************************/

#include <iostream>
using namespace std;

class Solution
{
public:
	double myPow(double x, int n)
	{
		if (n < 0)
			x = 1 / x;

		// 快速幂
		double ans = 1;
		double cur_product = x;
		for (long i = abs(n); i > 0; i /= 2)
		{
			if (i % 2)
				ans *= cur_product;
			cur_product = cur_product * cur_product;
		}
		return ans;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
