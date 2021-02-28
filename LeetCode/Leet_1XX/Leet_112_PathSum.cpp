/**************************************************
	> File Name:  Leet_112_PathSum.cpp
	> Author:     Leuckart
	> Time:       2019-08-01 21:37
**************************************************/

#include <iostream>
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
	bool hasPathSum(TreeNode *root, int sum)
	{
		if (root == nullptr)
			return false;
		if (root->val == sum && root->left == nullptr && root->right == nullptr)
			return true;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
