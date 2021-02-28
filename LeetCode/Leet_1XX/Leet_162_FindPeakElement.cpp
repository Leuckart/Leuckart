/**************************************************
	> File Name:  Leet_162_FindPeakElement.cpp
	> Author:     Leuckart
	> Time:       2020-09-12 02:18
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int findPeakElement(const vector<int> &nums)
	{
		int lhs = 0;
		int rhs = nums.size() - 1;
		while (lhs < rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (nums[mid] < nums[mid + 1])
				lhs = mid + 1;
			else
				rhs = mid;
		}
		return lhs;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
