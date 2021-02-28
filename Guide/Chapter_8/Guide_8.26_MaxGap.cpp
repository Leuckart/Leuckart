/**************************************************
	> File Name:  Guide_8.26_MaxGap.cpp
	> Author:     Leuckart
	> Time:       2020-10-22 01:32
**************************************************/

#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int maxGap(const vector<int> &data)
	{
		if (data.size() < 2)
			return 0;

		const int max_val = *max_element(data.cbegin(), data.cend());
		const int min_val = *min_element(data.cbegin(), data.cend());
		if (min_val == max_val)
			return 0;

		vector<bool> hasNum(data.size() + 1, 0);
		vector<int> maxs(data.size() + 1, 0);
		vector<int> mins(data.size() + 1, 0);

		for (int i = 0; i < data.size(); ++i)
		{
			int bid = data.size() * (data[i] - min_val) / (max_val - min_val);

			mins[bid] = hasNum[bid] ? min(mins[bid], data[i]) : data[i];
			maxs[bid] = hasNum[bid] ? max(maxs[bid], data[i]) : data[i];
			hasNum[bid] = true;
		}
	}

	static int bucket(long num, long len, long min, long max)
	{
		return (int)((num - min) * len / (max - min));
	}
};

int main(int argc, char *argv[])
{
	//assert(Solution::missNumber({-1, 0, 2, 1, 3, 5}) == 4);
	return 0;
}
