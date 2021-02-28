/**************************************************
	> File Name:  Guide_4.21_NQueens.cpp
	> Author:     Leuckart
	> Time:       2020-10-09 22:47
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int getNumber(const int n)
	{
		if (n < 1)
			return 0;

		vector<int> record(n, 0);
		return process(record, 0);
	}

private:
	static int process(vector<int> &record, int idx)
	{
		if (idx == record.size())
			return 1;

		int result = 0;
		for (int i = 0; i < record.size(); ++i)
		{
			if (isValid(record, idx, i))
			{
				record[idx] = i;
				result += process(record, idx + 1);
			}
		}
		return result;
	}

	static bool isValid(const vector<int> &record, const int row, const int col)
	{
		for (int i = 0; i < row; ++i)
			if (col == record[i] || abs(record[i] - col) == abs(i - row))
				return false;
		return true;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::getNumber(8) == 92);
	return 0;
}
