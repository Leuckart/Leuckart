/**************************************************
	> File Name:  Leet_051_NQueens.cpp
	> Author:     Leuckart
	> Time:       2019-07-15 20:57
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> result;
		vector<string> element(n, string(n, '.'));
		solveNQueensCore(result, element, 0);
		return result;
	}

private:
	void solveNQueensCore(vector<vector<string>> &result, vector<string> &element, int row)
	{
		if (row == element.size())
		{
			result.push_back(element);
			return;
		}

		for (int c = 0; c < element.size(); ++c)
		{
			bool flag = true;
			for (int r = 0; r < row; ++r)
			{
				if (element[r][c] == 'Q' ||
					(c - (row - r) >= 0 && element[r][c - (row - r)] == 'Q') ||
					(c + (row - r) < element.size() && element[r][c + (row - r)] == 'Q'))
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				element[row][c] = 'Q';
				solveNQueensCore(result, element, row + 1);
				element[row][c] = '.';
			}
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
