/**************************************************
	> File Name:  Leet_144_BinaryTreePreorderTraversal.cpp
	> Author:     Leuckart
	> Time:       2020-04-17 00:39
**************************************************/

#include <iostream>
#include <vector>
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
	vector<int> preorderTraversal(TreeNode *root)
	{
		if (root == nullptr)
			return {};

		vector<int> result;
		stack<TreeNode *> S;
		S.push(root);

		while (!S.empty())
		{
			TreeNode *cur = S.top();
			S.pop();
			result.push_back(cur->val);

			if (cur->right)
				S.push(cur->right);
			if (cur->left)
				S.push(cur->left);
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
