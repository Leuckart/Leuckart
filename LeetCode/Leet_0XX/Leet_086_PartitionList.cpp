/**************************************************
	> File Name:  Leet_086_PartitionList.cpp
	> Author:     Leuckart
	> Time:       2019-07-26 15:48
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
	ListNode *partition(ListNode *head, int x)
	{
		if (head == nullptr)
			return nullptr;

		ListNode *head_1 = nullptr;
		ListNode *head_2 = nullptr;
		ListNode *ptr_1 = nullptr;
		ListNode *ptr_2 = nullptr;

		while (head)
		{
			if (head->val < x)
			{
				if (head_1 == nullptr)
					ptr_1 = head_1 = head;
				else
				{
					ptr_1->next = head;
					ptr_1 = ptr_1->next;
				}
			}
			else
			{
				if (head_2 == nullptr)
					ptr_2 = head_2 = head;
				else
				{
					ptr_2->next = head;
					ptr_2 = ptr_2->next;
				}
			}
			head = head->next;
		}
		if (head_1 == nullptr && head_2 == nullptr)
			return nullptr;
		if (head_1 == nullptr && head_2)
			return head_2;
		if (head_1 && head_2 == nullptr)
			return head_1;
		ptr_2->next = nullptr;
		ptr_1->next = head_2;
		return head_1;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
