/**************************************************
	> File Name:  Guide_8.08_LongestIntegratedLength.cpp
	> Author:     Leuckart
	> Time:       2020-10-14 17:59
**************************************************/

#include <unordered_set>
#include <iostream>
#include <climits>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int getLIL(const vector<int> &data)
	{
		if (data.empty())
			return 0;

		int max_len = 0;
		for (int i = 0; i < data.size(); ++i)
		{
			int max_val = INT_MIN;
			int min_val = INT_MAX;
			unordered_set<int> St;

			for (int j = i; j < data.size(); ++j)
			{
				if (St.count(data[j]))
					break;

				St.insert(data[j]);
				max_val = max(max_val, data[j]);
				min_val = min(min_val, data[j]);
				if ((max_val - min_val) == (j - i))
					max_len = max(max_len, j - i + 1);
			}
		}
		return max_len;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::getLIL({5, 5, 3, 2, 6, 4, 3}) == 5);
	return 0;
}
