/**************************************************
	> File Name:  Leet_143_ReorderList.cpp
	> Author:     Leuckart
	> Time:       2020-09-07 20:18
**************************************************/

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	void reorderList(ListNode *head)
	{
		if (head == nullptr)
			return;

		ListNode *fast = head;
		ListNode *slow = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		fast = slow->next;
		slow->next = nullptr;
		slow = nullptr;

		// 翻转后半部分链表
		while (fast)
		{
			ListNode *nxt = fast->next;
			fast->next = slow;
			slow = fast;
			fast = nxt;
		}

		fast = head;
		while (slow)
		{
			ListNode *nxt1 = fast->next;
			ListNode *nxt2 = slow->next;
			fast->next = slow;
			slow->next = nxt1;
			fast = nxt1;
			slow = nxt2;
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
