/**************************************************
	> File Name:  Leet_142_LinkedListCycle2.cpp
	> Author:     Leuckart
	> Time:       2020-09-05 00:20
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
	ListNode *detectCycle(ListNode *head)
	{
		ListNode *fast = head;
		ListNode *slow = head;

		bool flag = false;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow)
			{
				flag = true;
				break;
			}
		}

		if (!flag)
			return nullptr;

		int size = 1;
		while ((fast = fast->next) != slow)
			++size;

		fast = head;
		while (size-- > 0)
			fast = fast->next;

		slow = head;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
