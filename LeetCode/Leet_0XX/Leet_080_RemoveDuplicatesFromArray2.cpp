/**************************************************
	> File Name:  Leet_080_RemoveDuplicatesFromArray2.cpp
	> Author:     Leuckart
	> Time:       2019-07-23 18:25
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		int pos = 0;
		for (int begin = 0, end = 0; begin < nums.size(); begin = end)
		{
			while (end < nums.size() && nums[begin] == nums[end])
				end++;

			for (int i = 0; i < end - begin && i < 2; i++)
				nums[pos + i] = nums[begin];
			pos += (end - begin >= 2 ? 2 : end - begin);
		}
		nums.erase(nums.begin() + pos, nums.end());
		return pos;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
