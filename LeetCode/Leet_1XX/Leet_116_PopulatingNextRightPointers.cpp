/**************************************************
	> File Name:  Leet_116_PopulatingNextRightPointers.cpp
	> Author:     Leuckart
	> Time:       2020-02-12 18:12
**************************************************/

#include <iostream>
#include <deque>
using namespace std;

class Node
{
public:
	int val;
	Node *left;
	Node *right;
	Node *next;

	Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
	Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
	Node(int _val, Node *_left, Node *_right, Node *_next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
	Node *connect(Node *root)
	{
		if (root == nullptr)
			return nullptr;

		deque<Node *> D;
		D.push_front(root);

		while (!D.empty())
		{
			Node *post = nullptr;
			int level_size = D.size();
			while (level_size-- > 0)
			{
				Node *cur = D.back();
				D.pop_back();
				cur->next = post;
				post = cur;

				if (cur->right)
					D.push_front(cur->right);
				if (cur->left)
					D.push_front(cur->left);
			}
		}
		return root;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
