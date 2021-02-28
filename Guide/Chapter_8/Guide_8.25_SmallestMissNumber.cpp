/**************************************************
	> File Name:  Guide_8.25_SmallestMissNumber.cpp
	> Author:     Leuckart
	> Time:       2020-10-21 23:34
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int missNumber(vector<int> data)
	{
		int l = 0;
		int r = data.size();
		while (l < r)
		{
			if (data[l] == l + 1)
				++l;
			else if (data[l] <= l || data[l] > r || data[l] == data[data[l] - 1])
				data[l] = data[--r];
			else
				swap(data[l], data[data[l] - 1]);
		}
		return l + 1;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::missNumber({-1, 0, 2, 1, 3, 5}) == 4);
	return 0;
}
