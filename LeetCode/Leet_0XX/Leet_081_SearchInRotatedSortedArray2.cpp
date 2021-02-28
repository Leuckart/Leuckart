/**************************************************
	> File Name:  Leet_081_SearchInRotatedSortedArray2.cpp
	> Author:     Leuckart
	> Time:       2019-07-24 00:28
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool search(const vector<int> &nums, const int target)
	{
		if (nums.size() == 1)
			return nums[0] == target;

		int lhs = 0;
		int rhs = nums.size() - 1;
		while (lhs < rhs)
		{
			while (lhs < nums.size() - 1 && nums[lhs] == nums[lhs + 1])
				++lhs;
			while (rhs > 0 && nums[rhs] == nums[rhs - 1])
				--rhs;

			int mid = (lhs + rhs) / 2;
			if (nums[lhs] == target || nums[mid] == target || nums[rhs] == target)
				return true;

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
		return false;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
