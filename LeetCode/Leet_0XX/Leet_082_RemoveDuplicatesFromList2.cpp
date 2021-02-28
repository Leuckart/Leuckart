/**************************************************
	> File Name:  Leet_082_RemoveDuplicatesFromList2.cpp
	> Author:     Leuckart
	> Time:       2019-07-24 02:01
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
	ListNode *deleteDuplicates(ListNode *head)
	{
		while (head && head->next && head->val == head->next->val)
		{
			while (head && head->next && head->val == head->next->val)
				head = head->next;
			head = head->next;
		}
		if (head == nullptr)
			return nullptr;

		for (ListNode *pos = head, *slow = head->next, *fast = head->next; fast; slow = fast)
		{
			while (fast && fast->val == slow->val)
				fast = fast->next;

			if (slow->next == fast)
				pos = slow;
			else
				pos->next = fast;
		}
		return head;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
