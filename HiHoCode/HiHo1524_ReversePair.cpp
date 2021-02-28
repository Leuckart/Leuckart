/**************************************************
	> File Name:  HiHo1524_ReversePair.cpp
	> Author:     Leuckart
	> Time:       2020-03-20 20:24
**************************************************/

/* http://hihocoder.com/problemset/problem/1524 */

#include <iostream>
#include <vector>
using namespace std;

long long Merge(vector<int> &data, vector<int> &copy, int lhs, int rhs)
{
	if (lhs >= rhs)
		return 0;

	int mid = (lhs + rhs) / 2;
	long long count_lhs = Merge(data, copy, lhs, mid);
	long long count_rhs = Merge(data, copy, mid + 1, rhs);
	long long count_cur = count_lhs + count_rhs;

	int pos = lhs, l = lhs, r = mid + 1;
	while (l <= mid && r <= rhs)
	{
		if (data[l] > data[r])
		{
			copy[pos++] = data[r++];
			count_cur += (mid - l + 1);
		}
		else
			copy[pos++] = data[l++];
	}

	while (l <= mid)
		copy[pos++] = data[l++];
	while (r <= rhs)
		copy[pos++] = data[r++];
	for (int i = lhs; i <= rhs; ++i)
		data[i] = copy[i];

	return count_cur;
}

int main()
{
	int N;
	cin >> N;

	vector<int> data(N, 0);
	vector<int> copy(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> data[i];

	cout << Merge(data, copy, 0, N - 1) << endl;
	return 0;
}
