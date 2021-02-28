/**************************************************
	> File Name:  Leet_089_GrayCode.cpp
	> Author:     Leuckart
	> Time:       2019-07-26 20:18
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> grayCode(const int n)
	{
		if (n == 0)
			return {0};

		vector<int> result = grayCode(n - 1);
		int size = 1 << (n - 1);

		for (int i = 0; i < size; ++i)
			result.push_back(result[size - 1 - i] + size);
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
