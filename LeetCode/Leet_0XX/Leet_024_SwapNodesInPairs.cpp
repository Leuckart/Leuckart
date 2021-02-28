/**************************************************
	> File Name:  Leet_024_SwapNodesInPairs.cpp
	> Author:     Leuckart
	> Time:       2019-07-02 13:31
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
	ListNode *swapPairs(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode *lhs = head;
		ListNode *rhs = head->next;
		lhs->next = swapPairs(rhs->next);
		rhs->next = lhs;
		return rhs;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
