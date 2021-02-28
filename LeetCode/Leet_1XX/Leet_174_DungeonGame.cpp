/**************************************************
	> File Name:  Leet_174_DungeonGame.cpp
	> Author:     Leuckart
	> Time:       2020-09-05 12:17
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int calculateMinimumHP(const vector<vector<int>> &dungeon)
	{
		vector<int> DP(dungeon[0].size(), INT32_MAX);
		DP.back() = 1;

		for (int i = dungeon.size() - 1; i >= 0; --i)
		{
			DP.back() -= dungeon[i].back();
			if (DP.back() <= 0)
				DP.back() = 1;

			for (int j = DP.size() - 2; j >= 0; --j)
			{
				DP[j] = min(DP[j], DP[j + 1]) - dungeon[i][j];
				if (DP[j] <= 0)
					DP[j] = 1;
			}
		}
		return DP.front();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
