/**************************************************
	> File Name:  HiHo1036_TrieMap.cpp
	> Author:     Leuckart
	> Time:       2017-08-20 03:06
**************************************************/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

static int nodeCnt = 0;
struct Node
{
	Node()
	{
		post = 0;
		for (int i = 0; i < 26; i++)
		{
			next[i] = 0;
		}
		post = 0;
		end = false;
	}
	int post;	 //后缀点的位置
	int next[26]; //经过26个字母的下一个可达的位置
	bool end;	 //是否为终点
} nodes[1000000]; //最多有1000000个点

//将str添加到trie图中
void build(string str)
{
	int strLen = str.length(), i = 0, current = 0;
	while (i < strLen)
	{
		if (nodes[current].next[str[i] - 'a'] == 0) //若当前点经过str[i]可达的位置未设置
		{
			nodes[current].next[str[i] - 'a'] = ++nodeCnt;
		}
		current = nodes[current].next[str[i] - 'a'];
		i++;
	}
	nodes[current].end = true;
}
//为trie图中的每个点添加它指向的后缀点位置
void addPost()
{
	queue<int> _int_nodes;
	_int_nodes.push(0);
	int current;
	while (!_int_nodes.empty())
	{
		current = _int_nodes.front();
		_int_nodes.pop();
		for (int i = 0; i < 26; i++)
		{
			if (nodes[current].next[i] != 0)
			{
				_int_nodes.push(nodes[current].next[i]);
				if (current != 0) //不是根结点，需要设置当前点的子节点的后缀=父结点的后缀经过i到达的点
				{
					nodes[nodes[current].next[i]].post = nodes[nodes[current].post].next[i];
				}
			}
			else //nodes[current].next[i] == -1当前点经过i没有可达的
			{
				nodes[current].next[i] = nodes[nodes[current].post].next[i];
			}
		}
	}
}

//查找str
bool search(string str)
{
	int strLen = str.length(), i = 0, current = 0;
	while (i < strLen)
	{
		if (nodes[nodes[current].next[str[i] - 'a']].end)
		{
			return true;
		}
		current = nodes[current].next[str[i] - 'a'];
		i++;
	}
	return false;
}
int main()
{
	int cnt;
	string str;
	cin >> cnt;
	while (cnt-- > 0)
	{
		cin >> str;
		build(str);
	}
	addPost();
	cin >> str;
	cout << (search(str) ? "YES" : "NO") << endl;
	return 0;
}
