/**************************************************
	> File Name:  Leet_201_BitwiseAndOfNumbersRange.cpp
	> Author:     Leuckart
	> Time:       2020-09-18 03:07
**************************************************/

#include <iostream>
using namespace std;

class Solution
{
public:
	int rangeBitwiseAnd(const int m, const int n)
	{
		int result = 0;
		for (int i = 0; i < 31; ++i)
		{
			int mask = 1 << i;
			if ((m & mask) && (n & mask) &&
				(n - m < mask))
				result |= 1 << i;
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
