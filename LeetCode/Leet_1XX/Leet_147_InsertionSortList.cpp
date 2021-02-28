/**************************************************
	> File Name:  Leet_147_InsertionSortList.cpp
	> Author:     Leuckart
	> Time:       2020-09-10 03:30
**************************************************/

#include <iostream>
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
	ListNode *insertionSortList(ListNode *head)
	{
		if (head == nullptr)
			return nullptr;

		ListNode *pre = head;
		ListNode *cur = head->next;

		while (cur)
		{
			if (cur->val <= head->val)
			{
				pre->next = cur->next;

				cur->next = head;
				head = cur;

				cur = pre->next;
			}
			else if (cur->val >= pre->val)
			{
				pre = pre->next;
				cur = cur->next;
			}
			else
			{
				ListNode *targ = head;
				while (targ->next != cur && targ->next->val <= cur->val)
					targ = targ->next;

				pre->next = cur->next;
				cur->next = targ->next;
				targ->next = cur;
				cur = pre->next;
			}
		}
		return head;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
