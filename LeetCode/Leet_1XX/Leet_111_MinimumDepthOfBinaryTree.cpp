/**************************************************
	> File Name:  Leet_111_MinimumDepthOfBinaryTree.cpp
	> Author:     Leuckart
	> Time:       2019-08-01 19:49
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
	int minDepth(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		if (root->left == nullptr)
			return 1 + minDepth(root->right);
		if (root->right == nullptr)
			return 1 + minDepth(root->left);
		return 1 + min(minDepth(root->left), minDepth(root->right));
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
