/**************************************************
	> File Name:  Leet_167_TwoSum2.cpp
	> Author:     Leuckart
	> Time:       2020-09-13 02:50
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(const vector<int> &numbers, const int target)
	{
		for (int i = 0, j = numbers.size() - 1; i < j;)
		{
			int cur = numbers[i] + numbers[j];
			if (cur == target)
				return {i + 1, j + 1};
			else if (cur < target)
				++i;
			else
				--j;
		}
		return {0, 0};
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
