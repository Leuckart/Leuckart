/**************************************************
	> File Name:  Guide_8.15_EvenInEvenOddInOdd.cpp
	> Author:     Leuckart
	> Time:       2020-10-19 02:08
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static void modify(vector<int> &data)
	{
		if (data.size() < 2)
			return;

		for (int even = 0, odd = 1; even < data.size() && odd < data.size();)
		{
			if (data[data.size() - 1] % 2)
			{
				swap(data[odd], data[data.size() - 1]);
				odd += 2;
			}
			else
			{
				swap(data[even], data[data.size() - 1]);
				even += 2;
			}
		}
	}
};

int main(int argc, char *argv[])
{
	vector<int> data{1, 8, 3, 2, 4, 6};
	Solution::modify(data);
	return 0;
}
