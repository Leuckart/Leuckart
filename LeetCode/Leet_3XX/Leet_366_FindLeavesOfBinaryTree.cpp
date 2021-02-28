/**************************************************
	> File Name:  Leet_366_FindLeavesOfBinaryTree.cpp
	> Author:     Leuckart
	> Time:       2020-04-09 22:30
**************************************************/

#include <iostream>
#include <vector>
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
	vector<vector<int>> findLeaves(TreeNode *root)
	{
		vector<vector<int>> result;
		findLeavesCore(result, root);
		return result;
	}

private:
	int findLeavesCore(vector<vector<int>> &result, TreeNode *root)
	{
		if (root == nullptr)
			return -1;

		int lhs_depth = findLeavesCore(result, root->left);
		int rhs_depth = findLeavesCore(result, root->right);
		int depth = 1 + max(lhs_depth, rhs_depth);

		if (result.size() == depth)
			result.push_back({root->val});
		else
			result[depth].push_back(root->val);
		return depth;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
