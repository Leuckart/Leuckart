/**************************************************
	> File Name:  Leet_263_UglyNumber.cpp
	> Author:     Leuckart
	> Time:       2020-04-01 15:47
**************************************************/

#include <iostream>
using namespace std;

class Solution
{
public:
	bool isUgly(int num)
	{
		if (num == 0)
			return false;
		while (num % 2 == 0)
			num /= 2;
		while (num % 3 == 0)
			num /= 3;
		while (num % 5 == 0)
			num /= 5;
		return num == 1;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
