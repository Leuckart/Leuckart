/**************************************************
	> File Name:  Leet_172_FactorialTrailingZeroes.cpp
	> Author:     Leuckart
	> Time:       2020-09-07 05:19
**************************************************/

#include <iostream>
using namespace std;

class Solution
{
public:
	int trailingZeroes(int n)
	{
		int counts = 0;
		while (n)
		{
			counts += n / 5;
			n /= 5;
		}
		return counts;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
