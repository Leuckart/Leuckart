/**************************************************
	> File Name:  Leet_173_BinarySearchTreeIterator.cpp
	> Author:     Leuckart
	> Time:       2020-09-07 19:20
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

class BSTIterator
{
public:
	BSTIterator(TreeNode *root)
	{
		while (root)
		{
			S.push(root);
			root = root->left;
		}
	}

	/** @return the next smallest number */
	int next()
	{
		TreeNode *cur = S.top();
		S.pop();

		for (TreeNode *iter = cur->right; iter; iter = iter->left)
			S.push(iter);
		return cur->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return !S.empty();
	}

private:
	stack<TreeNode *> S;
};

int main(int argc, char *argv[])
{
	BSTIterator *iterator = new BSTIterator(nullptr);
	return 0;
}
