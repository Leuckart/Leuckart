/**************************************************
	> File Name:  Leet_004_MedianOfTwoSortedArrays.cpp
	> Author:     Leuckart
	> Time:       2019-04-11 14:29
**************************************************/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solutions
{
public:
	double findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2)
	{
		int len1 = nums1.size();
		int len2 = nums2.size();
		if (len1 > len2)
			return findMedianSortedArrays(nums2, nums1);

		for (int lo = 0, hi = len1; lo <= hi;)
		{
			int part1 = (lo + hi) / 2;
			int part2 = (len1 + len2 + 1) / 2 - part1;

			if (part1 < len1 && nums1[part1] < nums2[part2 - 1])
				lo = part1 + 1;
			else if (part1 > 0 && nums1[part1 - 1] > nums2[part2])
				hi = part1 - 1;
			else
			{
				double lhs_max = max(part1 == 0 ? INT_MIN : nums1[part1 - 1],
									 part2 == 0 ? INT_MIN : nums2[part2 - 1]);
				double rhs_min = min(part1 == len1 ? INT_MAX : nums1[part1],
									 part2 == len2 ? INT_MAX : nums2[part2]);
				return (len1 + len2) % 2 ? lhs_max : (lhs_max + rhs_min) / 2;
			}
		}
		return -1;
	}
};

class Solution
{
public:
	double findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2)
	{
		int len1 = nums1.size();
		int len2 = nums2.size();
		if (len1 > len2)
			return findMedianSortedArrays(nums2, nums1);

		for (int lo = 0, hi = len1; lo <= hi;)
		{
			int part1 = (lo + hi) / 2;
			int part2 = (len1 + len2 + 1) / 2 - part1;

			if (part1 < len1 && nums1[part1] < nums2[part2 - 1])
				lo = part1 + 1;
			else if (part1 > 0 && nums1[part1 - 1] > nums2[part2])
				hi = part1 - 1;
			else
			{
				double lhs_max = max(part1 == 0 ? INT_MIN : nums1[part1 - 1],
									 part2 == 0 ? INT_MIN : nums2[part2 - 1]);
				double rhs_min = min(part1 == len1 ? INT_MAX : nums1[part1],
									 part2 == len2 ? INT_MAX : nums2[part2]);
				return (len1 + len2) % 2 ? lhs_max : (lhs_max + rhs_min) / 2;
			}
		}
		return -1;
	}
};

int main(int argc, char *argv[])
{
	Solutions sol;
	cout << sol.findMedianSortedArrays({1, 2}, {3, 4}) << endl;
	//cout << sol.findMedianSortedArrays({1, 3}, {2}) << endl;
	return 0;
}
