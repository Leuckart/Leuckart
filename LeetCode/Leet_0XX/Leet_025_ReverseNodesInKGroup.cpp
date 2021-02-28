/**************************************************
	> File Name:  Leet_025_ReverseNodesInKGroup.cpp
	> Author:     Leuckart
	> Time:       2019-07-02 14:05
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
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		stack<ListNode *> S;
		bool flag = true;

		ListNode *cur = head;
		ListNode *lhs = nullptr;
		ListNode *rhs = nullptr;
		while (1)
		{
			for (int i = 0; i < k && cur; ++i)
			{
				S.push(cur);
				cur = cur->next;
			}

			if (S.size() < k)
				break;
			if (flag)
			{
				head = S.top();
				flag = false;
			}

			if (lhs)
				lhs->next = S.top();
			rhs = S.top()->next;

			ListNode *rev = S.top();
			S.pop();
			while (!S.empty())
			{
				rev->next = S.top();
				rev = rev->next;
				S.pop();
			}
			lhs = rev;
			rev->next = rhs;
			cur = rhs;
		}

		return head;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
