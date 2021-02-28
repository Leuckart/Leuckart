/**************************************************
	> File Name:  Leet_103_BinaryTreeZigzagLevelOrderTraversal.cpp
	> Author:     Leuckart
	> Time:       2019-07-31 14:35
**************************************************/

#include <iostream>
#include <vector>
#include <deque>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode *root)
	{
		if (root == nullptr)
			return {};

		deque<TreeNode *> D;
		D.push_back(root);

		bool flag = true;
		vector<vector<int>> result;
		while (!D.empty())
		{
			result.push_back({});
			int level_size = D.size();

			if (flag)
			{
				while (level_size-- > 0)
				{
					TreeNode *tmp = D.front();
					D.pop_front();
					if (tmp->left)
						D.push_back(tmp->left);
					if (tmp->right)
						D.push_back(tmp->right);
					result.back().push_back(tmp->val);
				}
			}
			else
			{
				while (level_size-- > 0)
				{
					TreeNode *tmp = D.back();
					D.pop_back();

					if (tmp->right)
						D.push_front(tmp->right);
					if (tmp->left)
						D.push_front(tmp->left);
					result.back().push_back(tmp->val);
				}
			}
			flag = !flag;
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
