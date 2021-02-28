/**************************************************
	> File Name:  Leet_060_PermutationSequence.cpp
	> Author:     Leuckart
	> Time:       2019-07-18 23:34
**************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string getPermutation(int n, int k)
	{
		string result;
		vector<int> num{1, 2, 3, 4, 5, 6, 7, 8, 9};
		--k;

		for (int i = n - 1; i >= 0; --i)
		{
			int times = k / Fac[i];
			k %= Fac[i];

			result.push_back('0' + num[times]);
			num.erase(num.begin() + times);
		}
		return result;
	}

private:
	const vector<int> Fac{1, 1, 2, 6, 24, 120, 720, 5040, 40320};
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
