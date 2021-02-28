/**************************************************
	> File Name:  Leet_104_MaximumDepth.cpp
	> Author:     Leuckart
	> Time:       2019-07-06 21:55
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
	int maxDepth(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
