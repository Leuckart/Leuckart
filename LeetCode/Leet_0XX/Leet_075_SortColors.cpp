/**************************************************
	> File Name:  Leet_075_SortColors.cpp
	> Author:     Leuckart
	> Time:       2019-07-23 14:23
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void sortColors(vector<int> &nums)
	{
		vector<int> collection(3, 0);
		for (int i = 0; i < nums.size(); ++i)
			collection[nums[i]]++;

		fill(nums.begin(), nums.begin() + collection[0], 0);
		fill(nums.begin() + collection[0], nums.begin() + collection[0] + collection[1], 1);
		fill(nums.begin() + collection[0] + collection[1], nums.end(), 2);
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
