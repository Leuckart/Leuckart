/**************************************************
	> File Name:  Guide_8.21_MaxRectangle.cpp
	> Author:     Leuckart
	> Time:       2020-10-19 23:26
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int maxSize(const vector<vector<int>> &data)
	{
		vector<vector<int>> right(data.size(), vector<int>(data[0].size(), 0));
		vector<vector<int>> down(data.size(), vector<int>(data[0].size(), 0));
		setBorderMap(data, right, down);

		for (int size = min(data.size(), data[0].size()); size > 0; --size)
			if (validSize(right, down, size))
				return size;
		return 0;
	}

private:
	static void setBorderMap(const vector<vector<int>> &data, vector<vector<int>> &right, vector<vector<int>> &down)
	{
		const int row = data.size();
		const int col = data[0].size();
		if (data[row - 1][col - 1] == 1)
		{
			right[row - 1][col - 1] = 1;
			down[row - 1][col - 1] = 1;
		}
		for (int i = row - 2; i >= 0; --i)
		{
			if (data[i][col - 1] == 1)
			{
				right[i][col - 1] = 1;
				down[i][col - 1] = down[i + 1][col - 1] + 1;
			}
		}
		for (int i = col - 2; i >= 0; --i)
		{
			if (data[row - 1][i] == 1)
			{
				right[row - 1][i] = right[row - 1][i + 1] + 1;
				down[row - 1][i] = 1;
			}
		}
		for (int i = row - 2; i >= 0; --i)
		{
			for (int j = col - 2; j >= 0; --j)
			{
				if (data[i][j] == 1)
				{
					right[i][j] = right[i][j + 1] + 1;
					down[i][j] = down[i + 1][j] + 1;
				}
			}
		}
	}

	static bool validSize(const vector<vector<int>> &right, const vector<vector<int>> &down, const int size)
	{
		const int row = right.size();
		const int col = right[0].size();

		for (int i = 0; i <= row - size; ++i)
			for (int j = 0; j <= col - size; ++j)
				if (right[i][j] >= size &&
					down[i][j] >= size &&
					right[i + size - 1][j] >= size &&
					down[i][j + size - 1] >= size)
					return true;
		return false;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::maxSize({{0, 1, 1, 1, 1},
							  {0, 1, 0, 0, 1},
							  {0, 1, 0, 0, 1},
							  {0, 1, 1, 1, 1},
							  {0, 1, 0, 1, 1}}) == 4);
	return 0;
}
