/**************************************************
	> File Name:  Leet_098_ValidateBinarySearchTree.cpp
	> Author:     Leuckart
	> Time:       2019-07-30 18:08
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
	bool isValidBST(TreeNode *root)
	{
		TreeNode *prev = nullptr;
		return isValidBSTCore(root, prev);
	}

private:
	bool isValidBSTCore(TreeNode *root, TreeNode *&prev)
	{
		if (root == nullptr)
			return true;

		if (!isValidBSTCore(root->left, prev))
			return false;

		if (prev && prev->val >= root->val)
			return false;
		prev = root;

		if (!isValidBSTCore(root->right, prev))
			return false;
		return true;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
