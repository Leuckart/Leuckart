/**************************************************
	> File Name:  HiHo_1051_SubmissionCard.cpp
	> Author:     Leuckart
	> Time:       2020-03-21 13:34
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

int solveMax(const vector<int> &Data, const int Len)
{
	if (Len >= Data.size())
		return 100;

	int cur_max = Data[Len] - 1;
	for (int i = 1; i < Data.size() - Len; ++i)
		cur_max = max(cur_max, Data[i + Len] - Data[i - 1] - 1);

	cur_max = max(cur_max, 100 - Data[Data.size() - Len]);
	return cur_max;
}

int main()
{
	int T;
	cin >> T;

	while (T-- > 0)
	{
		int N, M;
		cin >> N >> M;
		vector<int> Data(N, 0);
		for (int i = 0; i < N; ++i)
			cin >> Data[i];

		cout << solveMax(Data, M) << endl;
	}
	return 0;
}

/*
5 1000
144 990
487 436
210 673
567 58
1056 897
*/
