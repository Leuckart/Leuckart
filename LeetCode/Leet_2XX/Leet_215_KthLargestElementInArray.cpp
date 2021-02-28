/**************************************************
	> File Name:  Leet_215_KthLargestElementInArray.cpp
	> Author:     Leuckart
	> Time:       2020-09-24 13:11
**************************************************/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int findKthLargest(vector<int> &nums, const int k)
	{
		return findKthLargestCore(nums, 0, nums.size() - 1, k);
	}

private:
	int findKthLargestCore(vector<int> &nums, const int beg, const int end, const int k)
	{
		if (beg == end)
			return nums[beg];

		int pivot = nums[end];
		int i = beg;
		int j = end;

		while (i < j)
		{
			while (i < j && nums[i] >= pivot)
				++i;
			nums[j] = nums[i];

			while (i < j && nums[j] < pivot)
				--j;
			nums[i] = nums[j];
		}
		nums[i] = pivot;

		if (i - beg + 1 == k)
			return pivot;
		else if (i - beg + 1 < k)
			return findKthLargestCore(nums, i + 1, end, k - i + beg - 1);
		else
			return findKthLargestCore(nums, beg, i - 1, k);
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
