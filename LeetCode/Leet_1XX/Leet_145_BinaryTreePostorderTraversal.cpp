/**************************************************
	> File Name:  Leet_145_BinaryTreePostorderTraversal.cpp
	> Author:     Leuckart
	> Time:       2019-04-18 17:26
**************************************************/

#include <algorithm>
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
	vector<int> postorderTraversal(TreeNode *root)
	{
		vector<int> result;
		stack<TreeNode *> S;
		if (root)
			S.push(root);

		while (!S.empty())
		{
			TreeNode *cur = S.top();
			result.push_back(cur->val);
			S.pop();

			if (cur->left)
				S.push(cur->left);
			if (cur->right)
				S.push(cur->right);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
