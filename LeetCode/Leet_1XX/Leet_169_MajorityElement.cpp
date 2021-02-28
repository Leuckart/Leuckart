/**************************************************
	> File Name:  Leet_169_MajorityElement.cpp
	> Author:     Leuckart
	> Time:       2020-09-13 03:00
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int majorityElement(const vector<int> &nums)
	{
		int major = nums[0];
		int major_times = 1;

		for (int i = 1; i < nums.size(); ++i)
		{
			if (major_times)
			{
				if (nums[i] == major)
					++major_times;
				else
					--major_times;
			}
			else
			{
				major = nums[i];
				major_times = 1;
			}
		}
		return major;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
