/**************************************************
	> File Name:  Leet_203_RemoveLinkedListElements.cpp
	> Author:     Leuckart
	> Time:       2020-09-18 04:11
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
	ListNode *removeElements(ListNode *head, int val)
	{
		ListNode *new_head = head;
		while (head && head->val == val)
		{
			new_head = head->next;
			delete head;
			head = new_head;
		}

		ListNode *cur = new_head;
		while (cur)
		{
			ListNode *nxt = cur->next;
			if (nxt && nxt->val == val)
			{
				cur->next = nxt->next;
				delete nxt;
			}
			else
				cur = cur->next;
		}
		return new_head;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
