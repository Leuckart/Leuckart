/**************************************************
	> File Name:  Leet_543_DiameterOfBinaryTree.cpp
	> Author:     Leuckart
	> Time:       2020-03-31 20:20
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
	int diameterOfBinaryTree(TreeNode *root)
	{
		if (!root)
			return 0;
		return max(depthOfBinaryTree(root->left) + depthOfBinaryTree(root->right),
				   max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
	}

private:
	int depthOfBinaryTree(TreeNode *root)
	{
		if (!root)
			return 0;
		return 1 + max(depthOfBinaryTree(root->left), depthOfBinaryTree(root->right));
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
