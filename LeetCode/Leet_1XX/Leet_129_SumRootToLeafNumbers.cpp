/**************************************************
	> File Name:  Leet_129_SumRootToLeafNumbers.cpp
	> Author:     Leuckart
	> Time:       2020-04-16 13:39
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
	int sumNumbers(TreeNode *root)
	{
		return sumNumbers(root, 0);
	}

private:
	int sumNumbers(TreeNode *root, int prev)
	{
		if (root == nullptr)
			return 0;
		if (root->left == nullptr && root->right == nullptr)
			return prev * 10 + root->val;
		return sumNumbers(root->left, prev * 10 + root->val) + sumNumbers(root->right, prev * 10 + root->val);
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
