/**************************************************
	> File Name:  Guide_8.11_LongestSumSubArray.cpp
	> Author:     Leuckart
	> Time:       2020-10-15 19:32
**************************************************/

#include <unordered_map>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int maxLength(const vector<int> &data, const int target)
	{
		unordered_map<int, int> Mp;
		Mp.insert(make_pair(0, -1));
		int max_len = 0;
		for (int i = 0, sum = 0; i < data.size(); ++i)
		{
			sum += data[i];
			if (Mp.count(sum - target))
				max_len = max(max_len, i - Mp[sum - target]);
			Mp.insert(make_pair(sum, i));
		}
		return max_len;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::maxLength({1, -2, 1, 1, 1}, 0) == 3);
	return 0;
}
