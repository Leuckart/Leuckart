/**************************************************
	> File Name:  Leet_199_BinaryTreeRightSideView.cpp
	> Author:     Leuckart
	> Time:       2020-04-17 02:53
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
	vector<int> rightSideView(TreeNode *root)
	{
		vector<int> result;
		queue<TreeNode *> Q;
		if (root)
			Q.push(root);

		while (!Q.empty())
		{
			result.push_back(Q.back()->val);
			int cur_size = Q.size();

			while (cur_size-- > 0)
			{
				TreeNode *node = Q.front();
				Q.pop();

				if (node->left)
					Q.push(node->left);
				if (node->right)
					Q.push(node->right);
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
