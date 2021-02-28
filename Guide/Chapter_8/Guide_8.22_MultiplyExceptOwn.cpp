/**************************************************
	> File Name:  Guide_8.22_MultiplyExceptOwn.cpp
	> Author:     Leuckart
	> Time:       2020-10-21 01:48
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static vector<int> product(const vector<int> &data)
	{
		if (data.size() < 2)
			return {};

		vector<int> result(data.size(), 0);
		result[0] = data[0];
		for (int i = 1; i < data.size(); ++i)
			result[i] = result[i - 1] * data[i];

		int rev = 1;
		for (int i = data.size() - 1; i > 0; --i)
		{
			result[i] = result[i - 1] * rev;
			rev *= data[i];
		}
		result[0] = rev;
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution::product({2, 1, 3, 4});
	return 0;
}
