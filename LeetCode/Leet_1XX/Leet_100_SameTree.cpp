/**************************************************
	> File Name:  Leet_100_SameTree.cpp
	> Author:     Leuckart
	> Time:       2019-06-07 22:00
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
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		if (p == nullptr && q == nullptr)
			return true;
		if (p && q)
			return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		return false;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
