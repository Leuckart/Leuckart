/**************************************************
	> File Name:  LeetCode_026_RemoveDuplicatesFromArray.cpp
	> Author:     Leuckart
	> Time:       2019-04-17 17:57
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		if (nums.size() < 2)
			return nums.size();

		int slow = 0;
		int fast = 1;
		while (fast < nums.size())
		{
			while (fast < nums.size() && nums[fast] == nums[slow])
				++fast;
			if (fast < nums.size())
				nums[slow + 1] = nums[fast];
			++slow;
		}
		while (nums.size() > slow)
			nums.pop_back();
		return slow;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
