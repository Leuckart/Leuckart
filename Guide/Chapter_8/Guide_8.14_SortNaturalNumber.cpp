/**************************************************
	> File Name:  Guide_8.14_SortNaturalNumber.cpp
	> Author:     Leuckart
	> Time:       2020-10-18 21:02
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static void sort(vector<int> &data)
	{
		for (int i = 0; i < data.size(); ++i)
			while (data[i] != i + 1)
				swap(data[i], data[data[i] - 1]);
	}
};

int main(int argc, char *argv[])
{
	vector<int> data{8, 2, 1, 6, 9, 3, 7, 5, 4};
	Solution::sort(data);
	return 0;
}
