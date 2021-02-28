/**************************************************
	> File Name:  Leet_019_RemoveNthNode.cpp
	> Author:     Leuckart
	> Time:       2019-06-28 00:15
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
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		ListNode *fast = head;
		while (n-- > 0)
			fast = fast->next;

		if (fast == nullptr)
		{
			ListNode *tmp = head;
			head = head->next;
			delete tmp;
			return head;
		}

		ListNode *slow = head;
		while (fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}

		ListNode *tmp = slow->next;
		slow->next = slow->next->next;
		delete tmp;
		return head;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
