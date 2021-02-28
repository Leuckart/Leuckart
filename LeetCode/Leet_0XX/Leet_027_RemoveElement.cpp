/**************************************************
	> File Name:  Leet_027_RemoveElement.cpp
	> Author:     Leuckart
	> Time:       2019-06-09 14:50
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeElement(vector<int> &nums, int val)
	{
		int slow = 0;
		int fast = 0;

		while (fast < nums.size())
		{
			while (fast < nums.size() && nums[fast] == val)
				++fast;
			if (fast >= nums.size())
				break;
			nums[slow] = nums[fast];
			++slow;
			++fast;
		}
		return slow;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
