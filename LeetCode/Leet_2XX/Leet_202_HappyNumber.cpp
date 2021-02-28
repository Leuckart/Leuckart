/**************************************************
	> File Name:  Leet_202_HappyNumber.cpp
	> Author:     Leuckart
	> Time:       2019-06-28 07:06
**************************************************/

#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isHappy(int n)
	{
		unordered_set<int> S;
		while (S.count(n) == 0)
		{
			S.insert(n);
			int new_n = 0;
			while (n > 0)
			{
				new_n += (n % 10) * (n % 10);
				n /= 10;
			}
			n = new_n;
		}
		return S.count(1);
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
