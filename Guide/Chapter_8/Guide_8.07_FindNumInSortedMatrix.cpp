/**************************************************
	> File Name:  Guide_8.07_FindNumInSortedMatrix.cpp
	> Author:     Leuckart
	> Time:       2020-10-14 16:16
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static bool isContain(const vector<vector<int>> &matrix, const int target)
	{
		int i = 0;
		int j = matrix[0].size() - 1;
		while (i < matrix.size() && j >= 0)
		{
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] < target)
				++i;
			else
				--j;
		}
		return false;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::isContain({{0, 1, 2, 3, 4, 5, 6},
								{10, 12, 13, 15, 16, 17, 18},
								{23, 24, 25, 26, 27, 28, 29},
								{44, 45, 46, 47, 48, 49, 50},
								{65, 66, 67, 68, 69, 70, 71},
								{96, 97, 98, 99, 100, 111, 122},
								{166, 176, 186, 187, 190, 195, 200},
								{233, 243, 321, 341, 356, 370, 380}},
							   233) == true);
	return 0;
}
