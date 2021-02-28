/**************************************************
	> File Name:  Leet_222_CountCompleteTreeNodes.cpp
	> Author:     Leuckart
	> Time:       2020-09-07 19:59
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
	int countNodes(TreeNode *root)
	{
		if (root == nullptr)
			return 0;

		int lhs = getDepth(root->left);
		int rhs = getDepth(root->right);

		if (lhs == rhs)
			return 1 + ((1 << lhs) - 1) + countNodes(root->right);
		else
			return 1 + ((1 << rhs) - 1) + countNodes(root->left);
	}

private:
	int getDepth(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		return 1 + max(getDepth(root->left), getDepth(root->right));
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
