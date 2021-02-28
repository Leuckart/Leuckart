/**************************************************
	> File Name:  Leet_206_ReverseLinkedList.cpp
	> Author:     Leuckart
	> Time:       2020-09-18 18:11
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
	ListNode *reverseList(ListNode *head)
	{
		ListNode *slow = nullptr;
		ListNode *fast = head;
		while (fast)
		{
			ListNode *nxt = fast->next;
			fast->next = slow;
			slow = fast;
			fast = nxt;
		}
		return slow;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
