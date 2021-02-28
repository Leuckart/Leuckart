/**************************************************
	> File Name:  Leet_154_FindMinInRotatedSortedArray2.cpp
	> Author:     Leuckart
	> Time:       2020-02-16 18:54
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int findMin(const vector<int> &nums)
	{
		if (nums.empty())
			throw runtime_error("Array empty.");

		int lhs = 0;
		int rhs = nums.size() - 1;

		while (lhs < rhs)
		{
			if (nums[lhs] < nums[rhs])
				return nums[lhs];
			else if (nums[lhs] == nums[rhs])
				--rhs;
			else
			{
				int mid = (lhs + rhs) / 2;
				if (nums[lhs] <= nums[mid])
					lhs = mid + 1;
				else
					rhs = mid;
			}
		}
		return nums[lhs];
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
