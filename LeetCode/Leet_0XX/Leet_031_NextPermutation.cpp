/**************************************************
	> File Name:  Leet_031_NextPermutation.cpp
	> Author:     Leuckart
	> Time:       2019-07-04 17:50
**************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void nextPermutation(vector<int> &nums)
	{
		int index = nums.size() - 2;
		while (index >= 0 && nums[index] >= nums[index + 1])
			--index;

		// 不存在下一个更大的排列，则重排为最小的排列
		if (index < 0)
		{
			sort(nums.begin(), nums.end());
			return;
		}

		int index_swap = index + 1;
		for (int i = index + 1; i < nums.size(); ++i)
			if (nums[i] > nums[index] && nums[i] < nums[index_swap])
				index_swap = i;

		swap(nums[index], nums[index_swap]);
		sort(nums.begin() + index + 1, nums.end());
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
