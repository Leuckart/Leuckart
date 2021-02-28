/**************************************************
	> File Name:  Leet_033_SearchInRotatedSortedArray.cpp
	> Author:     Leuckart
	> Time:       2019-07-05 10:42
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int search(const vector<int> &nums, const int target)
	{
		if (nums.size() == 1)
			return nums[0] == target ? 0 : -1;

		int lhs = 0;
		int rhs = nums.size() - 1;
		while (lhs < rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (nums[lhs] == target)
				return lhs;
			if (nums[mid] == target)
				return mid;
			if (nums[rhs] == target)
				return rhs;

			if (nums[lhs] < nums[mid])
			{
				if (target < nums[mid] && target > nums[lhs])
					rhs = mid - 1;
				else
					lhs = mid + 1;
			}
			else
			{
				if (target > nums[mid] && target < nums[rhs])
					lhs = mid + 1;
				else
					rhs = mid - 1;
			}
		}
		return -1;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
