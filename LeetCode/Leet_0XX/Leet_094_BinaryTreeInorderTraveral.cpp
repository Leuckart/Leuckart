/**************************************************
	> File Name:  Leet_094_BinaryTreeInorderTraveral.cpp
	> Author:     Leuckart
	> Time:       2019-06-07 18:30
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
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> result;

		stack<TreeNode *> St;
		while (root)
		{
			St.push(root);
			root = root->left;
		}

		while (!St.empty())
		{
			TreeNode *cur = St.top();
			St.pop();
			result.push_back(cur->val);

			cur = cur->right;
			while (cur)
			{
				St.push(cur);
				cur = cur->left;
			}
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
