/**************************************************
	> File Name:  Leet_110_BalancedBinaryTree.cpp
	> Author:     Leuckart
	> Time:       2019-07-31 20:37
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
	bool isBalanced(TreeNode *root)
	{
		if (root == nullptr)
			return true;
		if (abs(isBalancedCore(root->left) - isBalancedCore(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right))
			return true;
		return false;
	}

private:
	int isBalancedCore(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		return 1 + max(isBalancedCore(root->left), isBalancedCore(root->right));
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
