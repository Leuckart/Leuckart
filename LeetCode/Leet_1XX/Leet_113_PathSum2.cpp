/**************************************************
	> File Name:  Leet_113_PathSum2.cpp
	> Author:     Leuckart
	> Time:       2019-08-01 21:56
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
	vector<vector<int>> pathSum(const TreeNode *const root, const int sum)
	{
		vector<vector<int>> result;
		vector<int> path;
		pathSumCore(result, path, root, sum);
		return result;
	}

private:
	void pathSumCore(vector<vector<int>> &result, vector<int> &path, const TreeNode *const root, const int sum)
	{
		if (root == nullptr)
			return;
		if (root->val == sum && root->left == nullptr && root->right == nullptr)
		{
			path.push_back(sum);
			result.push_back(path);
			path.pop_back();
			return;
		}

		path.push_back(root->val);
		if (root->left)
			pathSumCore(result, path, root->left, sum - root->val);
		if (root->right)
			pathSumCore(result, path, root->right, sum - root->val);
		path.pop_back();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
