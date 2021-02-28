/**************************************************
	> File Name:  Leet_136_SingleNumber.cpp
	> Author:     Leuckart
	> Time:       2020-09-03 07:03
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int singleNumber(vector<int> &nums)
	{
		int num = 0;
		for (int i = 0; i < nums.size(); ++i)
			num ^= nums[i];
		return num;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
