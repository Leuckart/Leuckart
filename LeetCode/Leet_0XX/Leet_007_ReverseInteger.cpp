/**************************************************
	> File Name:  LeetCode_007_ReverseInteger.cpp
	> Author:     Leuckart
	> Time:       2019-04-10 23:06
**************************************************/

#include <iostream>
#include <climits>

class Solution
{
public:
	int reverse(const int x)
	{
		bool be_negetive = x < 0;
		long posx = abs(x);

		long ans = 0;
		while (posx)
		{
			ans = 10 * ans + posx % 10;
			posx /= 10;
		}

		if (be_negetive)
			return (ans - 1 > INT_MAX) ? 0 : -ans;
		else
			return (ans > INT_MAX) ? 0 : ans;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
