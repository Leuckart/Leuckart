/**************************************************
	> File Name:  Leet_204_CountPrimes.cpp
	> Author:     Leuckart
	> Time:       2020-09-18 04:26
**************************************************/

#include <iostream>
using namespace std;

class Solution
{
public:
	int countPrimes(const int n)
	{
		if (n < 3)
			return 0;

		int result = 1;
		for (int i = 3; i < n; i += 2)
			result += isPrimeOdd(i);
		return result;
	}

private:
	bool isPrimeOdd(const int n)
	{
		int width = 0;
		while ((1 << (2 * width)) < n)
			++width;

		for (int i = 3; i <= (1 << width); i += 2)
			if (n % i == 0)
				return false;
		return true;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
