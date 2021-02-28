/**************************************************
	> File Name:  Leet_088_MergeSortedArray.cpp
	> Author:     Leuckart
	> Time:       2019-07-06 22:03
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
	{
		if (nums2.size() == 0)
			return;
		int end_point = m + n;
		--m;
		--n;

		while (n >= 0)
		{
			--end_point;
			if (m < 0 || nums2[n] >= nums1[m])
			{
				nums1[end_point] = nums2[n];
				--n;
			}
			else
			{
				nums1[end_point] = nums1[m];
				--m;
			}
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
