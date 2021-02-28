/**************************************************
	> File Name:  Leet_501_FindModeInBST.cpp
	> Author:     Leuckart
	> Time:       2020-09-24 19:45
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
	vector<int> findMode(TreeNode *root)
	{
		TreeNode *pre = nullptr;
		TreeNode *cur = root;
		vector<int> result;

		while (cur)
		{
			if (cur->left == nullptr)
			{
				update(cur->val, result);
				cur = cur->right;
				continue;
			}

			pre = cur->left;
			while (pre->right && pre->right != cur)
				pre = pre->right;

			if (pre->right == nullptr)
			{
				pre->right = cur;
				cur = cur->left;
			}
			else
			{
				pre->right = nullptr;
				update(cur->val, result);
				cur = cur->right;
			}
		}
		return result;
	}

private:
	int base, count, maxCount;

	void update(int x, vector<int> &result)
	{
		if (x == base)
			++count;
		else
		{
			count = 1;
			base = x;
		}

		if (count == maxCount)
			result.push_back(base);

		if (count > maxCount)
		{
			maxCount = count;
			result = vector<int>{base};
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
