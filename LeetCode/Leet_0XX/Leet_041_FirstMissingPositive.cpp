/**************************************************
	> File Name:  Leet_041_FirstMissingPositive.cpp
	> Author:     Leuckart
	> Time:       2019-07-11 16:33
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int firstMissingPositive(vector<int> &nums)
	{
		for (int i = 0; i < nums.size(); ++i)
			while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
				swap(nums[i], nums[nums[i] - 1]);

		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				return i + 1;
		return nums.size() + 1;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
