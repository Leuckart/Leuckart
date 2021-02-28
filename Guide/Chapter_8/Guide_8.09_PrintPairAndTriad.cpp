/**************************************************
	> File Name:  Guide_8.09_PrintPairAndTriad.cpp
	> Author:     Leuckart
	> Time:       2020-10-15 15:02
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static vector<pair<int, int>> getUniquePair(const vector<int> &data, const int target)
	{
		vector<pair<int, int>> result;
		if (data.size() < 2)
			return result;

		int l = 0;
		int r = data.size() - 1;
		while (l < r)
		{
			if (data[l] + data[r] < target)
				++l;
			else if (data[l] + data[r] > target)
				--r;
			else
			{
				if (l == 0 || data[l - 1] != data[l])
					result.push_back(make_pair(data[l], data[r]));
				++l;
				--r;
			}
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution::getUniquePair({-8, -4, -3, 0, 1, 2, 4, 5, 8, 9}, 10);
	return 0;
}
