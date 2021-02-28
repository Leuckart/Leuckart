/**************************************************
	> File Name:  Guide_4.01_Fibonacci.cpp
	> Author:     Leuckart
	> Time:       2020-10-03 23:21
**************************************************/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
	static int solveFibonacci(const int num)
	{
		if (num < 1)
			return 0;
		if (num < 3)
			return 1;

		vector<vector<int>> base{{1, 1}, {1, 0}};
		vector<vector<int>> result = matrixPower(base, num - 2);
		return result[0][0] + result[1][0];
	}

private:
	static vector<vector<int>> matrixPower(const vector<vector<int>> &mat, int power)
	{
		vector<vector<int>> result(mat.size(), vector<int>(mat[0].size()));
		for (int i = 0; i < result.size(); ++i)
			result[i][i] = 1;

		vector<vector<int>> mat_power = mat;
		while (power != 0)
		{
			if ((power & 1) != 0)
				result = mulMatrix(result, mat_power);
			mat_power = mulMatrix(mat_power, mat_power);
			power >>= 1;
		}
		return result;
	}

	static vector<vector<int>> mulMatrix(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2)
	{
		vector<vector<int>> result(mat1.size(), vector<int>(mat2[0].size(), 0));
		for (int i = 0; i < mat1.size(); ++i)
			for (int j = 0; j < mat2[0].size(); ++j)
				for (int k = 0; k < mat2.size(); ++k)
					result[i][j] += mat1[i][k] * mat2[k][j];
		return result;
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::solveFibonacci(20) == 6765);
	return 0;
}
