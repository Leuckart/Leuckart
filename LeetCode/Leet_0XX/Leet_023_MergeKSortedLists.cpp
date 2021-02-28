/**************************************************
	> File Name:  Leet_023_MergeKSortedLists.cpp
	> Author:     Leuckart
	> Time:       2019-07-01 18:19
**************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		priority_queue<ListNode *, vector<ListNode *>, cmp> Q;
		for (int i = 0; i < lists.size(); ++i)
			if (lists[i])
				Q.push(lists[i]);

		ListNode *root = nullptr;
		ListNode *cur = nullptr;
		while (!Q.empty())
		{
			ListNode *top = Q.top();
			Q.pop();
			if (top->next)
				Q.push(top->next);

			if (root == nullptr)
			{
				root = top;
				cur = top;
			}
			else
			{
				cur->next = top;
				cur = cur->next;
			}
		}
		return root;
	}

private:
	struct cmp
	{
		bool operator()(ListNode *a, ListNode *b)
		{
			return a->val > b->val;
		}
	};
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
