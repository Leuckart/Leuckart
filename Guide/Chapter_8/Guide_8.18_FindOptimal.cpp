/**************************************************
	> File Name:  Guide_8.18_FindOptimal.cpp
	> Author:     Leuckart
	> Time:       2020-10-19 18:18
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int findOptimal(const vector<int> &data)
	{
		if (data.empty())
			return -1;
		if (data.size() == 1 || data[0] < data[1])
			return 0;
		if (data[data.size() - 1] < data[data.size() - 2])
			return data.size() - 1;

		int l = 1;
		int r = data.size() - 2;
		while (l < r)
		{
			int m = (l + r) / 2;
			if (data[m] > data[m - 1])
				r = m - 1;
			else if (data[m] > data[m + 1])
				l = m + 1;
			else
				return m;
		}
		return l;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::findOptimal({6, 5, 3, 4, 6, 7, 8}) == 2);
	return 0;
}
