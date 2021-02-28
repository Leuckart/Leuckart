/**************************************************
	> File Name:  Leet_073_SetMatrixZeroes.cpp
	> Author:     Leuckart
	> Time:       2019-07-22 15:55
**************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
	void setZeroes(vector<vector<int>> &matrix)
	{
		set<int> set_row;
		set<int> set_col;

		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				if (matrix[i][j] == 0)
				{
					set_row.insert(i);
					set_col.insert(j);
				}
			}
		}

		for (set<int>::const_iterator iter = set_row.cbegin(); iter != set_row.cend(); ++iter)
			for (int i = 0; i < matrix[0].size(); ++i)
				matrix[*iter][i] = 0;
		for (set<int>::const_iterator iter = set_col.cbegin(); iter != set_col.cend(); ++iter)
			for (int i = 0; i < matrix.size(); ++i)
				matrix[i][*iter] = 0;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
