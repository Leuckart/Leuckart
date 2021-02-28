/**************************************************
	> File Name:  Leet_231_PowerOfTwo.cpp
	> Author:     Leuckart
	> Time:       2019-07-18 17:03
**************************************************/

#include <iostream>
using namespace std;

class Solution
{
public:
	bool isPowerOfTwo(const int n)
	{
		return n > 0 && (n & (n - 1)) == 0;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
