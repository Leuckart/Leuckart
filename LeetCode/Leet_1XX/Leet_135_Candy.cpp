/**************************************************
	> File Name:  Leet_135_Candy.cpp
	> Author:     Leuckart
	> Time:       2020-09-03 06:53
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int candy(vector<int> &ratings)
	{
		vector<int> lhs(ratings.size(), 1);
		for (int i = 1; i < lhs.size(); ++i)
			if (ratings[i] > ratings[i - 1])
				lhs[i] = lhs[i - 1] + 1;

		vector<int> rhs(ratings.size(), 1);
		for (int i = rhs.size() - 2; i >= 0; --i)
			if (ratings[i] > ratings[i + 1])
				rhs[i] = rhs[i + 1] + 1;

		int result = 0;
		for (int i = 0; i < ratings.size(); ++i)
			result += max(lhs[i], rhs[i]);
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
