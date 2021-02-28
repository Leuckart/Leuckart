/**************************************************
	> File Name:  Leet_124_BinaryTreeMaximumPathSum.cpp
	> Author:     Leuckart
	> Time:       2020-04-14 00:18
**************************************************/

#include <iostream>
#include <climits>
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
	int maxPathSum(TreeNode *root)
	{
		int val = INT_MIN;
		maxPathSumCore(root, val);
		return val;
	}

private:
	int maxPathSumCore(TreeNode *root, int &val)
	{
		if (root == nullptr)
			return 0;

		int lhs = maxPathSumCore(root->left, val);
		int rhs = maxPathSumCore(root->right, val);

		int lmr = root->val + max(0, lhs) + max(0, rhs);
		int ret = root->val + max(0, max(lhs, rhs));

		val = max(val, max(lmr, ret));
		return ret;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
