/**************************************************
	> File Name:  Leet_107_BinaryTreeLevelOrderTraversal2.cpp
	> Author:     Leuckart
	> Time:       2019-07-31 19:51
**************************************************/

#include <algorithm>
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
	vector<vector<int>> levelOrderBottom(TreeNode *root)
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
		reverse(result.begin(), result.end());
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
