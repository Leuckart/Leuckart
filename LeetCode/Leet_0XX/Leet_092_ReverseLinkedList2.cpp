/**************************************************
	> File Name:  Leet_092_ReverseLinkedList2.cpp
	> Author:     Leuckart
	> Time:       2019-07-29 13:13
**************************************************/

#include <iostream>
#include <stack>
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
	ListNode *reverseBetween(ListNode *head, int m, int n)
	{
		ListNode *ptr_m = head;
		for (int i = 1; i < m; i++)
			ptr_m = ptr_m->next;

		stack<int> S;
		ListNode *ptr_n = ptr_m;
		S.push(ptr_n->val);

		for (int i = 0; i < n - m; i++)
		{
			ptr_n = ptr_n->next;
			S.push(ptr_n->val);
		}

		while (ptr_m != ptr_n->next)
		{
			ptr_m->val = S.top();
			S.pop();
			ptr_m = ptr_m->next;
		}
		return head;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
