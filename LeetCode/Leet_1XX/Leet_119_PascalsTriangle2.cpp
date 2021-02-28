/**************************************************
	> File Name:  Leet_119_PascalsTriangle2.cpp
	> Author:     Leuckart
	> Time:       2020-02-12 17:47
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getRow(const int rowIndex)
	{
		vector<int> result(rowIndex + 1, 1);
		for (int i = 2; i <= rowIndex; ++i)
			for (int j = i - 1; j >= 1; --j)
				result[j] = result[j - 1] + result[j];
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
