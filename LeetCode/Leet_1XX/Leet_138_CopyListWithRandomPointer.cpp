/**************************************************
	> File Name:  Leet_138_CopyListWithRandomPointer.cpp
	> Author:     Leuckart
	> Time:       2020-09-03 13:28
**************************************************/

#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
	int val;
	Node *next;
	Node *random;

	Node(int _val)
	{
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

class Solution
{
public:
	Node *copyRandomList(Node *head)
	{
		if (!head)
			return nullptr;

		map<Node *, Node *> Map;
		Node *root = new Node(head->val);

		for (Node *cur = head, *cur_cp = root; cur; cur = cur->next, cur_cp = cur_cp->next)
		{
			Map[cur] = cur_cp;
			if (cur->next)
				cur_cp->next = new Node(cur->next->val);
		}

		for (Node *cur = head, *cur_cp = root; cur; cur = cur->next, cur_cp = cur_cp->next)
			if (cur->random)
				cur_cp->random = Map[cur->random];

		return root;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
