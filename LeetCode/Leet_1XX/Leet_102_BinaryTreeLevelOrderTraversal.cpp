/**************************************************
	> File Name:  Leet_102_BinaryTreeLevelOrderTraversal.cpp
	> Author:     Leuckart
	> Time:       2019-07-30 23:51
**************************************************/

#include <iostream>
#include <vector>
#include <queue>
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
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		if (root == nullptr)
			return {};

		queue<TreeNode *> Q;
		Q.push(root);

		vector<vector<int>> result;
		while (!Q.empty())
		{
			result.push_back({});

			int level_size = Q.size();
			while (level_size-- > 0)
			{
				TreeNode *tmp = Q.front();
				Q.pop();
				if (tmp->left)
					Q.push(tmp->left);
				if (tmp->right)
					Q.push(tmp->right);

				result.back().push_back(tmp->val);
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
