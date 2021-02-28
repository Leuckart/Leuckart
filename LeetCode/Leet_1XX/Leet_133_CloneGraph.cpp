/**************************************************
	> File Name:  Leet_133_CloneGraph.cpp
	> Author:     Leuckart
	> Time:       2020-09-03 01:43
**************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class Node
{
public:
	int val;
	vector<Node *> neighbors;

	Node()
	{
		val = 0;
		neighbors = vector<Node *>();
	}

	Node(int _val)
	{
		val = _val;
		neighbors = vector<Node *>();
	}

	Node(int _val, vector<Node *> _neighbors)
	{
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution
{
public:
	Node *cloneGraph(Node *node)
	{
		if (!node)
			return nullptr;

		Node *root = new Node(node->val);
		map<Node *, Node *> Mp; // Origin -> Clone
		Mp.insert(make_pair(node, root));

		stack<Node *> St;
		St.push(node);

		while (!St.empty())
		{
			Node *cur = St.top();
			Node *cur_cp = Mp.find(cur)->second;
			St.pop();

			for (int i = 0; i < cur->neighbors.size(); ++i)
			{
				if (Mp.find(cur->neighbors[i]) == Mp.end())
				{
					Node *new_node = new Node(cur->neighbors[i]->val);
					Mp.insert(make_pair(cur->neighbors[i], new_node));
					St.push(cur->neighbors[i]);
				}

				map<Node *, Node *>::iterator iter = Mp.find(cur->neighbors[i]);
				cur_cp->neighbors.push_back(iter->second);
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
