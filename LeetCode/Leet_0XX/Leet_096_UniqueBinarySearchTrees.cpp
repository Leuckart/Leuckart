/**************************************************
	> File Name:  Leet_096_UniqueBinarySearchTrees.cpp
	> Author:     Leuckart
	> Time:       2019-07-30 22:49
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
	int numTrees(int n)
	{
		vector<int> DP(n + 1, 0);
		DP[0] = 1;
		for (int pos = 1; pos <= n; ++pos)
			for (int i = 0; i < pos; ++i)
				DP[pos] += DP[i] * DP[pos - 1 - i];
		return DP[n];
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
