/**************************************************
	> File Name:  Leet_191_NumberOf1Bits.cpp
	> Author:     Leuckart
	> Time:       2020-09-07 04:57
**************************************************/

#include <iostream>
using namespace std;

class Solution
{
public:
	int hammingWeight(uint32_t n)
	{
		int counts = 0;
		while (n)
		{
			n &= (n - 1);
			++counts;
		}
		return counts;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
