/**************************************************
	> File Name:  Leet_069_Sqrt.cpp
	> Author:     Leuckart
	> Time:       2019-06-28 01:12
**************************************************/

#include <iostream>
using namespace std;

class Solution
{
public:
	int mySqrt(const int x)
	{
		if (x == 0)
			return 0;

		int bit = 1;
		for (long i = 1; i <= x; i <<= 1)
			++bit;

		long lhs = 1 << (bit / 2 - 1);
		long rhs = 1 << (bit / 2);

		while (lhs < rhs - 1)
		{
			long mid = (lhs + rhs) >> 1;
			if (mid * mid < x)
				lhs = mid;
			else if (mid * mid > x)
				rhs = mid;
			else
				return mid;
		}
		return (lhs + rhs) >> 1;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
