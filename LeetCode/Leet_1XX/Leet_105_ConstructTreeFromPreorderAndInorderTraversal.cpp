/**************************************************
	> File Name:  Leet_105_ConstructTreeFromPreorderAndInorderTraversal.cpp
	> Author:     Leuckart
	> Time:       2019-07-31 16:12
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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		if (preorder.empty() || inorder.empty())
			return nullptr;

		return buildTreeRecursive(preorder, 0, preorder.size() - 1,
								  inorder, 0, inorder.size() - 1);
	}

private:
	TreeNode *buildTreeRecursive(const vector<int> &preorder, const int pre_beg, const int pre_end,
								 const vector<int> &inorder, const int in_beg, const int in_end)
	{
		TreeNode *root = new TreeNode(preorder[pre_beg]);
		if (pre_beg == pre_end && in_beg == in_end && preorder[pre_beg] == inorder[in_beg])
			return root;
		if (pre_beg == pre_end || in_beg == in_end)
			throw exception();

		int in_root = in_beg;
		while (in_root <= in_end && inorder[in_root] != preorder[pre_beg])
			++in_root;
		if (in_root > in_end)
			throw exception();

		int lhs_size = in_root - in_beg;
		int rhs_size = in_end - in_root;

		if (lhs_size)
			root->left = buildTreeRecursive(preorder, pre_beg + 1, pre_beg + lhs_size,
											inorder, in_beg, in_root - 1);
		if (rhs_size)
			root->right = buildTreeRecursive(preorder, pre_beg + lhs_size + 1, pre_end,
											 inorder, in_root + 1, in_end);
		return root;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
