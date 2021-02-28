/**************************************************
	> File Name:  Leet_189_RotateArray.cpp
	> Author:     Leuckart
	> Time:       2020-09-07 05:08
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void rotate(vector<int> &nums, int k)
	{
		k %= nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
