/**************************************************
	> File Name:  Leet_149_MaxPointsOnALine.cpp
	> Author:     Leuckart
	> Time:       2020-09-10 12:50
**************************************************/

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
	int maxPoints(const vector<vector<int>> &points)
	{
		if (points.size() < 2)
			return points.size();

		int result = 0;
		for (int i = 0; i < points.size() - 1; ++i)
		{
			map<pair<int, int>, int> M;

			int duplicate = 1;
			for (int j = i + 1; j < points.size(); ++j)
			{
				int delta_x = points[i][0] - points[j][0];
				int delta_y = points[i][1] - points[j][1];
				if (delta_x == 0 && delta_y == 0)
				{
					++duplicate;
					continue;
				}

				pair<int, int> grad = make_pair(0, INT_MAX);
				if (delta_x)
				{
					int gcd = getGCD(delta_x, delta_y);
					delta_x /= gcd;
					delta_y /= gcd;
					grad = make_pair(delta_x, delta_y);
				}

				if (M.find(grad) == M.end())
					M[grad] = 1;
				else
					M[grad]++;
			}
			map<pair<int, int>, int>::const_iterator cur_max = max_element(M.cbegin(), M.cend(),
																		   [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) { return a.second < b.second; });
			result = max(result, duplicate + (cur_max == M.cend() ? 0 : cur_max->second));
		}
		return result;
	}

private:
	int getGCD(int a, int b)
	{
		if (b == 0)
			return a;
		return getGCD(b, a % b);
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
