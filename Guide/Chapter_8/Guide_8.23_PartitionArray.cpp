/**************************************************
	> File Name:  Guide_8.23_PartitionArray.cpp
	> Author:     Leuckart
	> Time:       2020-10-21 04:20
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static void leftUnique(vector<int> &data)
	{
		if (data.size() < 2)
			return;

		int l = 0;
		int r = 0;
		while (r < data.size())
		{
			int rx = r + 1;
			while (rx < data.size() && data[rx] == data[r])
				++rx;
			swap(data[l], data[r]);
			++l;
			r = rx;
		}
	}
};

int main(int argc, char *argv[])
{
	vector<int> data{1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 7, 7, 8, 8, 8, 9};
	Solution::leftUnique(data);
	return 0;
}
