/**************************************************
	> File Name:  Leet_101_SymmetricTree.cpp
	> Author:     Leuckart
	> Time:       2019-06-07 22:11
**************************************************/

#include <iostream>
#include <stack>
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
	bool isSymmetric(TreeNode *root)
	{
		if (root == nullptr)
			return true;
		return isSymmetricCore(root->left, root->right);
	}

private:
	bool isSymmetricCore(TreeNode *root1, TreeNode *root2)
	{
		if (root1 == nullptr && root2 == nullptr)
			return true;
		if (root1 && root2)
			return root1->val == root2->val &&
				   isSymmetricCore(root1->left, root2->right) &&
				   isSymmetricCore(root1->right, root2->left);
		return false;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
