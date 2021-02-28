/**************************************************
	> File Name:  Leet_137_SingleNumber2.cpp
	> Author:     Leuckart
	> Time:       2020-09-03 13:17
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int singleNumber(vector<int> &nums)
	{
		int result = 0;

		for (int bit = 0; bit < 32; ++bit)
		{
			int times = 0;
			for (int i = 0; i < nums.size(); ++i)
				if (nums[i] & 1 << bit)
					++times;

			if (times % 3)
				result += 1 << bit;
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
