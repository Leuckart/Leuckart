/**************************************************
	> File Name:  Guide_8.20_MaxTopK.cpp
	> Author:     Leuckart
	> Time:       2020-10-19 21:59
**************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	static vector<int> topK(const vector<vector<int>> &data, const int k)
	{
		vector<int> index(data.size(), 0);
		for (int i = 0; i < data.size(); ++i)
			index[i] = data[i].size() - 1;

		priority_queue<pair<int, int>> Q;
		for (int i = 0; i < data.size(); ++i)
		{
			if (index[i] >= 0)
			{
				Q.push(make_pair(data[i][index[i]], i));
				--index[i];
			}
		}

		vector<int> result;
		for (int i = 0; i < k; ++i)
		{
			pair<int, int> cur = Q.top();
			result.push_back(cur.first);

			if (index[cur.second] >= 0)
			{
				Q.push(make_pair(data[cur.second][index[cur.second]], cur.second));
				--index[cur.second];
			}
			Q.pop();
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	auto res = Solution::topK({{219, 405, 538, 845, 971},
							   {148, 558},
							   {52, 99, 348, 691}},
							  5);
	return 0;
}
