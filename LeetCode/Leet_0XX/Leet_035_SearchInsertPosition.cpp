/**************************************************
	> File Name:  Leet_035_SearchInsertPosition.cpp
	> Author:     Leuckart
	> Time:       2019-07-01 05:07
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int searchInsert(const vector<int> &nums, const int target)
	{
		if (nums.empty())
			return 0;

		int lhs = 0;
		int rhs = nums.size() - 1;
		while (lhs < rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (nums[mid] < target)
				lhs = mid + 1;
			else if (nums[mid] > target)
				rhs = mid - 1;
			else
				return mid;
		}
		if (nums[lhs] < target)
			return lhs + 1;
		else
			return lhs;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
