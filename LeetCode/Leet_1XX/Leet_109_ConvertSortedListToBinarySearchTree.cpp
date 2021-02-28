/**************************************************
	> File Name:  Leet_109_ConvertSortedListToBinarySearchTree.cpp
	> Author:     Leuckart
	> Time:       2019-07-31 17:53
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

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
	TreeNode *sortedListToBST(ListNode *head)
	{
		return sortedListToBSTCore(head, nullptr);
	}

private:
	TreeNode *sortedListToBSTCore(ListNode *head, ListNode *tail)
	{
		if (head == tail)
			return nullptr;

		ListNode *slow = head;
		ListNode *fast = head;
		while (fast != tail && fast->next != tail)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		TreeNode *root = new TreeNode(slow->val);
		root->left = sortedListToBSTCore(head, slow);
		root->right = sortedListToBSTCore(slow->next, tail);
		return root;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
