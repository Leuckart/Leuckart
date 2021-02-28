/**************************************************
	> File Name:  Leet_052_NQueens2.cpp
	> Author:     Leuckart
	> Time:       2019-07-16 15:48
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int totalNQueens(int n)
	{
		vector<int> element(n, -1);
		return totalNQueensCore(element, 0);
	}

private:
	int totalNQueensCore(vector<int> &element, int row)
	{
		if (row == element.size())
			return 1;

		int sum = 0;
		for (int c = 0; c < element.size(); ++c)
		{
			bool flag = true;
			for (int r = 0; r < row; ++r)
			{
				if (element[r] == c ||
					element[r] == c - (row - r) ||
					element[r] == c + (row - r))
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				element[row] = c;
				sum += totalNQueensCore(element, row + 1);
				element[row] = -1;
			}
		}
		return sum;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
