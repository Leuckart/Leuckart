/**************************************************
	> File Name:  Leet_001_TwoSum.cpp
	> Author:     Leuckart
	> Time:       2019-04-10 16:09
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static vector<int> twoSum(const vector<int> &nums, const int target)
	{
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			int to_find = target - nums[i];
			for (int j = i + 1; j < nums.size(); ++j)
				if (nums[j] == to_find)
					return {i, j};
		}
		return {};
	}
};

int main(int argc, char *argv[])
{
	return 0;
}
