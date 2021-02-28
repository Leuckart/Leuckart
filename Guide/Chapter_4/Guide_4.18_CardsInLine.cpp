/**************************************************
	> File Name:  Guide_4.18_CardsInLine.cpp
	> Author:     Leuckart
	> Time:       2020-10-08 22:10
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int win(const vector<int> &data)
	{
		if (data.empty())
			return 0;

		vector<vector<int>> fast(data.size(), vector<int>(data.size(), 0)); // data[i:j]中，先手的得分
		vector<vector<int>> slow(data.size(), vector<int>(data.size(), 0)); // data[i:j]中，后手的得分

		for (int i = data.size() - 1; i >= 0; --i)
		{
			fast[i][i] = data[i];
			for (int j = i + 1; j < data.size(); ++j)
			{
				fast[i][j] = max(data[i] + slow[i + 1][j], data[j] + slow[i][j - 1]);
				slow[i][j] = min(fast[i + 1][j], fast[i][j - 1]);
			}
		}
		return max(fast.front().back(), slow.front().back());
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::win({1, 9, 1}) == 9);
	return 0;
}
