/**************************************************
	> File Name:  Leet_148_SortList.cpp
	> Author:     Leuckart
	> Time:       2020-09-10 03:58
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
	ListNode *sortList(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode *slow = head;
		ListNode *fast = head->next;

		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode *mid = slow->next;
		slow->next = nullptr;

		ListNode *lhs = sortList(head);
		ListNode *rhs = sortList(mid);

		ListNode *new_head;
		if (lhs->val <= rhs->val)
		{
			new_head = lhs;
			lhs = lhs->next;
		}
		else
		{
			new_head = rhs;
			rhs = rhs->next;
		}

		ListNode *cur = new_head;
		while (lhs && rhs)
		{
			if (lhs->val <= rhs->val)
			{
				cur->next = lhs;
				lhs = lhs->next;
			}
			else
			{
				cur->next = rhs;
				rhs = rhs->next;
			}
			cur = cur->next;
		}
		cur->next = lhs ? lhs : rhs;
		return new_head;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
