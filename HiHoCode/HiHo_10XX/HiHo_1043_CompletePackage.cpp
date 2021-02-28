/**************************************************
	> File Name:  HiHo_1043_CompletePackage.cpp
	> Author:     Leuckart
	> Time:       2020-03-21 13:00
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

int solver(const vector<int> &needs, const vector<int> &values, const int number, const int money)
{
	vector<vector<int>> DP(number + 1, vector<int>(money + 1, 0));
	for (int i = 1; i <= number; ++i)
	{
		for (int j = 1; j <= money; ++j)
		{
			if (j >= needs[i - 1])
				DP[i][j] = max(DP[i - 1][j], DP[i][j - needs[i - 1]] + values[i - 1]);
			else
				DP[i][j] = DP[i - 1][j];
		}
	}
	return DP.back().back();
}

int solver_v2(const vector<int> &needs, const vector<int> &values, const int number, const int money)
{
	vector<int> DP(money + 1, 0);
	for (int i = 1; i <= number; ++i)
		for (int j = needs[i - 1]; j <= money; ++j)
			DP[j] = max(DP[j], DP[j - needs[i - 1]] + values[i - 1]);
	return DP.back();
}

int main()
{
	int number, money;
	cin >> number >> money;

	vector<int> needs(number, 0);
	vector<int> values(number, 0);
	for (int i = 0; i < number; ++i)
		cin >> needs[i] >> values[i];

	cout << solver(needs, values, number, money) << endl;
	cout << solver_v2(needs, values, number, money) << endl;
	return 0;
}
