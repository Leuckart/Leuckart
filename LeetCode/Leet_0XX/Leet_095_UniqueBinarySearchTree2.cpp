/**************************************************
	> File Name:  Leet_095_UniqueBinarySearchTree2.cpp
	> Author:     Leuckart
	> Time:       2019-07-30 18:35
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
	vector<TreeNode *> generateTrees(int n)
	{
		if (n == 0)
			return {};
		return generateTreesCore(1, n);
	}

private:
	vector<TreeNode *> generateTreesCore(int beg, int end)
	{
		if (beg > end)
			return {nullptr};

		vector<TreeNode *> result;
		for (int i = beg; i <= end; ++i)
		{
			vector<TreeNode *> pLeft = generateTreesCore(beg, i - 1);
			vector<TreeNode *> pRight = generateTreesCore(i + 1, end);

			for (int l = 0; l < pLeft.size(); ++l)
			{
				for (int r = 0; r < pRight.size(); ++r)
				{
					TreeNode *cur = new TreeNode(i);
					cur->left = pLeft[l];
					cur->right = pRight[r];
					result.push_back(cur);
				}
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
