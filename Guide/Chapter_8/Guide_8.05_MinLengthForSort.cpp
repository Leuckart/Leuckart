/**************************************************
	> File Name:  Guide_8.05_MinLengthForSort.cpp
	> Author:     Leuckart
	> Time:       2020-10-11 23:34
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int minLength(const vector<int> &data)
	{
		if (data.size() < 2)
			return 0;

		int min_val = data.back();
		int min_idx = -1;
		for (int i = data.size() - 2; i >= 0; --i)
		{
			if (data[i] > min_val)
				min_idx = i;
			else
				min_val = data[i];
		}
		if (min_idx == -1)
			return 0;

		int max_val = data.front();
		int max_idx = -1;
		for (int i = 1; i < data.size(); ++i)
		{
			if (data[i] < max_val)
				max_idx = i;
			else
				max_val = data[i];
		}

		return max_idx - min_idx + 1;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::minLength({1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19}) == 7);
	return 0;
}
