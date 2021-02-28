/**************************************************
	> File Name:  Leet_141_LinkedListCycle.cpp
	> Author:     Leuckart
	> Time:       2020-09-05 00:09
**************************************************/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	bool hasCycle(ListNode *head)
	{
		ListNode *fast = head;
		ListNode *slow = head;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow)
				return true;
		}
		return false;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
