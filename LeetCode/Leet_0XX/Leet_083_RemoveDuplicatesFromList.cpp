/**************************************************
	> File Name:  Leet_083_RemoveDuplicatesFromList.cpp
	> Author:     Leuckart
	> Time:       2019-07-24 13:06
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
		for (ListNode *slow = head, *fast = head; slow;)
		{
			while (fast && fast->val == slow->val)
				fast = fast->next;
			slow->next = fast;
			slow = slow->next;
		}
		return head;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
