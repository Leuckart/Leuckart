/**************************************************
	> File Name:  Leet_002_AddTwoNumbers.cpp
	> Author:     Leuckart
	> Time:       2019-04-10 21:36
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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *root = new ListNode(0);
		ListNode *cur = root;
		bool be_overflow = false;

		while (l1 || l2)
		{
			cur->val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + be_overflow;

			be_overflow = cur->val > 9;
			cur->val %= 10;

			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
			if (l1 || l2 || be_overflow)
			{
				cur->next = new ListNode(0);
				cur = cur->next;
			}
		}

		if (be_overflow)
			cur->val = 1;
		return root;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
