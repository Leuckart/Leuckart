/**************************************************
	> File Name:  HiHo1033_AlternatingSum.cpp
	> Author:     Leuckart
	> Time:       2017-08-02 16:21
**************************************************/

#include <iostream>
#include <cstring>
using namespace std;

const long MOD = 1000000007;

struct Node
{
	long sum;
	long num;
	Node()
	{
		sum = 0;
		num = -1;
	}
};

Node dp[19][20][162];

int BIT[19];
long base[19];

Node dfs(int len, int dig, int sum, bool begin_zero, bool end_flag)
{
	Node t;
	t.sum = 0;
	t.num = 0;
	if (len <= 0 || len >= 20 || dig < 0 || dig > 9 || sum < -80 || sum > 81)
		return t;
	if (!end_flag && dp[len][dig + (begin_zero ? 0 : 10)][sum + 80].num != -1)
		return dp[len][dig + (begin_zero ? 0 : 10)][sum + 80];
	if (len == 1)
	{
		if (dig != sum)
			return t;
		t.num = 1;
		t.sum = sum;
		return t;
	}
	int end = end_flag ? BIT[len - 2] : 9;
	int newsum = dig - sum;
	Node tmp;
	for (int j = 0; j < end + 1; j++)
	{
		if (!begin_zero)
		{
			tmp = dfs(len - 1, j, sum, j != 0, end_flag && (j == end));
		}
		else
		{
			tmp = dfs(len - 1, j, newsum, true, end_flag && (j == end));
		}
		t.num += tmp.num;
		t.sum = ((t.sum + tmp.sum) % MOD + ((tmp.num * dig) % MOD * base[len - 1]) % MOD) % MOD;
	}
	if (!end_flag)
		dp[len][dig + (begin_zero ? 0 : 10)][sum + 80] = t;
	return t;
}

long solve(long n, int s)
{
	if (n <= 0)
		return 0;

	for (int i = 0; i < 19; i++)
	{
		BIT[i] = 0;
	}

	int now = 0;
	while (n)
	{
		BIT[now++] = n % 10;
		n /= 10;
	}
	return dfs(now + 1, 0, s, false, true).sum;
}

int main()
{
	long smallNum, bigNum, alterSum;

	base[0] = 1;
	for (int i = 1; i < 19; i++)
	{
		base[i] = (base[i - 1] * 10) % MOD;
	}

	cin >> smallNum >> bigNum >> alterSum;
	long result = (solve(bigNum, alterSum) - solve(smallNum - 1, alterSum) + MOD) % MOD;
	cout << result << endl;
	return 0;
}
