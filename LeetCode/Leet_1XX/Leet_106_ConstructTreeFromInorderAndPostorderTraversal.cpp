/**************************************************
	> File Name:  Leet_106_ConstructTreeFromInorderAndPostorderTraversal.cpp
	> Author:     Leuckart
	> Time:       2019-07-31 17:26
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
	TreeNode *buildTree(const vector<int> &inorder, const vector<int> &postorder)
	{
		if (inorder.empty() || postorder.empty())
			return nullptr;

		return buildTreeCore(inorder, 0, inorder.size() - 1,
							 postorder, 0, postorder.size() - 1);
	}

private:
	TreeNode *buildTreeCore(const vector<int> &inorder, const int in_beg, const int in_end,
							const vector<int> &postorder, const int post_beg, const int post_end)
	{
		TreeNode *root = new TreeNode(postorder[post_end]);
		if (in_beg == in_end && post_beg == post_end && inorder[in_beg] == postorder[post_beg])
			return root;
		if (in_beg == in_end || post_beg == post_end)
			throw exception();

		int in_root = in_beg;
		while (in_root <= in_end && inorder[in_root] != root->val)
			++in_root;
		if (in_root > in_end)
			throw exception();

		const int lhs_size = in_root - in_beg;
		const int rhs_size = in_end - in_root;

		if (lhs_size)
			root->left = buildTreeCore(inorder, in_beg, in_root - 1,
									   postorder, post_beg, post_beg + lhs_size - 1);
		if (rhs_size)
			root->right = buildTreeCore(inorder, in_root + 1, in_end,
										postorder, post_beg + lhs_size, post_end - 1);
		return root;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
