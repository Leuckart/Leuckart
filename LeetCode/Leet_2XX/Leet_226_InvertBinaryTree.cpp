/**************************************************
	> File Name:  Leet_226_InvertBinaryTree.cpp
	> Author:     Leuckart
	> Time:       2020-09-24 14:04
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
	TreeNode *invertTree(TreeNode *root)
	{
		if (root == nullptr)
			return nullptr;

		TreeNode *tmp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(tmp);

		return root;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
