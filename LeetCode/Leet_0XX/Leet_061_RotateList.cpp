/**************************************************
	> File Name:  Leet_061_RotateList.cpp
	> Author:     Leuckart
	> Time:       2019-07-20 23:24
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
	ListNode *rotateRight(ListNode *head, int k)
	{
		if (head == nullptr)
			return nullptr;

		int len = 1;
		ListNode *tail = head;
		while (tail->next != nullptr)
		{
			tail = tail->next;
			++len;
		}
		k %= len;

		if (k == 0)
			return head;

		ListNode *ptr = head;
		for (int i = 1; i < len - k; ++i)
			ptr = ptr->next;

		tail->next = head;
		ListNode *new_head = ptr->next;
		ptr->next = nullptr;

		return new_head;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
