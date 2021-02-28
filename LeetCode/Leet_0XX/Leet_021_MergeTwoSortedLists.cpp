/**************************************************
	> File Name:  Leet_021_MergeTwoSortedLists.cpp
	> Author:     Leuckart
	> Time:       2019-04-12 02:17
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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

		if (l1->val <= l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
