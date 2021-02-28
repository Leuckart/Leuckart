/**************************************************
	> File Name:  Leet_029_DivideTwoIntegers.cpp
	> Author:     Leuckart
	> Time:       2019-06-29 19:00
**************************************************/

#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		if (divisor == INT_MIN)
			return dividend == INT_MIN;
		bool posFlag = (dividend >= 0 && divisor > 0) || (dividend <= 0 && divisor < 0);

		int ans = 0;
		if (dividend == INT_MIN)
		{
			if (divisor == -1)
				return INT_MAX;
			if (divisor == 1)
				return INT_MIN;
			dividend += abs(divisor);
			++ans;
		}
		dividend = abs(dividend);
		divisor = abs(divisor);

		while (dividend >= divisor)
		{
			int bit = 0;
			while ((dividend >> (bit + 1)) > divisor)
				++bit;
			if (bit == -1)
				break;
			ans += 1 << bit;
			dividend -= divisor << bit;
		}
		return posFlag ? ans : -ans;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
