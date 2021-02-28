/**************************************************
	> File Name:  Guide_8.13_SmallSum.cpp
	> Author:     Leuckart
	> Time:       2020-10-17 19:49
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static long smallSum(vector<int> &data)
	{
		if (data.empty())
			return 0;
		return recursive(data, 0, data.size() - 1);
	}

private:
	static long recursive(vector<int> &data, const int lhs, const int rhs)
	{
		if (lhs == rhs)
			return 0;
		int mid = (lhs + rhs) / 2;
		return recursive(data, lhs, mid) + recursive(data, mid + 1, rhs) + merge(data, lhs, rhs);
	}

	static long merge(vector<int> &data, const int lhs, const int rhs)
	{
		long result = 0;
		int mid = (lhs + rhs) / 2;
		int li = lhs;
		int ri = mid + 1;

		int idx = 0;
		vector<int> help(rhs - lhs + 1, 0);
		while (li <= mid && ri <= rhs)
		{
			if (data[li] <= data[ri])
			{
				result += data[li] * (rhs - ri + 1);
				help[idx++] = data[li++];
			}
			else
				help[idx++] = data[ri++];
		}

		while (li <= mid)
			help[idx++] = data[li++];
		while (ri <= rhs)
			help[idx++] = data[ri++];
		for (int i = 0; i < help.size(); ++i)
			data[lhs + i] = help[i];
		return result;
	}
};

int main(int argc, char *argv[])
{
	vector<int> data{3, 1, 2, 4, 6, 2, 7, 8, 1};
	assert(Solution::smallSum(data) == 64);
	return 0;
}
