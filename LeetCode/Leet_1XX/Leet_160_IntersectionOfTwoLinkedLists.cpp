/**************************************************
	> File Name:  Leet_160_IntersectionOfTwoLinkedLists.cpp
	> Author:     Leuckart
	> Time:       2020-09-12 01:30
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		ListNode *pA = headA;
		ListNode *pB = headB;

		while (pA && pB)
		{
			pA = pA->next;
			pB = pB->next;
		}

		if (pA == nullptr)
			pA = headB;
		else
			pB = headA;

		while (pA && pB)
		{
			pA = pA->next;
			pB = pB->next;
		}

		if (pA == nullptr)
			pA = headB;
		else
			pB = headA;

		while (pA != pB && pA && pB)
		{
			pA = pA->next;
			pB = pB->next;
		}
		return (pA && pB) ? pA : nullptr;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
