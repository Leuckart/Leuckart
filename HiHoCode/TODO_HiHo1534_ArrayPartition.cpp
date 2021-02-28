/**************************************************
	> File Name:  HiHo1534_ArrayPartition.cpp
	> Author:     Leuckart
	> Time:       2017-07-20 14:40
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long num;
	cin >> num;
	long ans = 0;

	vector<long> nums(num, 0);
	for (long i = 0; i < num; i++)
		cin >> nums[i];

	vector<long> LSum(num, 0);
	LSum[0] = nums[0];
	for (long i = 1; i < num; i++)
		LSum[i] = LSum[i - 1] + nums[i];

	vector<long> RSum(num, 0);
	RSum[num - 1] = nums[num - 1];
	for (long i = num - 2; i >= 0; i--)
		RSum[i] = RSum[i + 1] + nums[i];

	long allSum = LSum[num - 1];
	long part = allSum >= 0 ? (allSum / 3) : (allSum / 3 - 1);

	vector<bool> Forward_0(num, 0);
	vector<bool> Forward_1(num, 0);
	for (int i = 0; i < num; ++i)
	{
		Forward_0[i] = LSum[i] == part;
		Forward_1[i] = LSum[i] == part + 1;
	}

	vector<int> Backward_0(num, 0);
	vector<int> Backward_1(num, 0);
	Backward_0[num - 1] = nums[num - 1] == part;
	Backward_1[num - 1] = nums[num - 1] == (part + 1);
	for (long i = num - 2; i >= 0; i--)
	{
		Backward_0[i] = Backward_0[i + 1] + (RSum[i] == part);
		Backward_1[i] = Backward_1[i + 1] + (RSum[i] == (part + 1));
	}

	long flag = allSum % 3;

	for (long i = 0; i < num - 2; i++)
	{
		if (flag == 0)
			ans += Forward_0[i] * Backward_0[i + 2];
		else if (flag == 1)
			ans += Forward_0[i] * (Backward_0[i + 2] + Backward_1[i + 2]) +
				   Forward_1[i] * Backward_0[i + 2];
		else
			ans += Forward_0[i] * Backward_1[i + 2] +
				   Forward_1[i] * (Backward_0[i + 2] + Backward_1[i + 2]);
	}

	cout << ans << endl;
	return 0;
}
