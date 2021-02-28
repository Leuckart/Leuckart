/**************************************************
	> File Name:  Leet_114_FlattenBinaryTreeToLinkedList.cpp
	> Author:     Leuckart
	> Time:       2019-08-02 17:38
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
	void flatten(TreeNode *root)
	{
		if (root == nullptr)
			return;

		TreeNode *post = nullptr;
		flattenCore(root, post);
	}

private:
	void flattenCore(TreeNode *root, TreeNode *&post)
	{
		if (root == nullptr)
			return;

		flattenCore(root->right, post);
		flattenCore(root->left, post);

		root->left = nullptr;
		root->right = post;
		post = root;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
