/**************************************************
	> File Name:  Leet_099_RecoverBinarySearchTree.cpp
	> Author:     Leuckart
	> Time:       2019-07-29 22:28
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
	void recoverTree(TreeNode *root)
	{
		TreeNode *prev = nullptr;
		TreeNode *wrong_1st = nullptr;
		TreeNode *wrong_2nd = nullptr;
		recoverTreeCore(root, prev, wrong_1st, wrong_2nd);
		swap(wrong_1st->val, wrong_2nd->val);
	}

private:
	void recoverTreeCore(TreeNode *root, TreeNode *&prev, TreeNode *&wrong_1st, TreeNode *&wrong_2nd)
	{
		if (root == nullptr)
			return;

		recoverTreeCore(root->left, prev, wrong_1st, wrong_2nd);

		if (prev && prev->val >= root->val && wrong_1st == nullptr)
			wrong_1st = prev;
		// 注意此时 wrong_2nd 的赋值
		if (prev && prev->val >= root->val && wrong_1st)
			wrong_2nd = root;
		prev = root;

		recoverTreeCore(root->right, prev, wrong_1st, wrong_2nd);
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
