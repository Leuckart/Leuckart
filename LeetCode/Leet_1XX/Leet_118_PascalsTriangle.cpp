/**************************************************
	> File Name:  Leet_118_PascalsTriangle.cpp
	> Author:     Leuckart
	> Time:       2020-02-12 16:28
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> generate(const int numRows)
	{
		vector<vector<int>> result;
		for (int i = 0; i < numRows; ++i)
		{
			result.emplace_back(vector<int>(i + 1, 1));
			for (int j = 1; j < i; ++j)
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
