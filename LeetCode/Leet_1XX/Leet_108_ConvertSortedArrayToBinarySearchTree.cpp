/**************************************************
	> File Name:  Leet_108_ConvertSortedArrayToBinarySearchTree.cpp
	> Author:     Leuckart
	> Time:       2019-07-31 20:16
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
	TreeNode *sortedArrayToBST(const vector<int> &nums)
	{
		if (nums.empty())
			return nullptr;
		return sortedArrayToBSTCore(nums, 0, nums.size() - 1);
	}

private:
	TreeNode *sortedArrayToBSTCore(const vector<int> &nums, const int beg, const int end)
	{
		const int mid = (beg + end) / 2;
		TreeNode *root = new TreeNode(nums[mid]);

		if (beg < mid)
			root->left = sortedArrayToBSTCore(nums, beg, mid - 1);
		if (mid < end)
			root->right = sortedArrayToBSTCore(nums, mid + 1, end);
		return root;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
