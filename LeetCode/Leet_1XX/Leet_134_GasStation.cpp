/**************************************************
	> File Name:  Leet_134_GasStation.cpp
	> Author:     Leuckart
	> Time:       2020-09-03 05:26
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost)
	{
		int min_index = -1;
		int min_value = INT32_MAX;

		int value = 0;
		for (int i = 0; i < gas.size(); ++i)
		{
			value += gas[i] - cost[i];

			if (value < min_value)
			{
				min_index = i;
				min_value = value;
			}
		}
		return value < 0 ? -1 : (min_index + 1) % gas.size();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
