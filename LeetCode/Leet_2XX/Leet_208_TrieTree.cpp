/**************************************************
	> File Name:  Leet_208_TrieTree.cpp
	> Author:     Leuckart
	> Time:       2020-09-21 03:12
**************************************************/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Trie
{
public:
	Trie()
	{
		is_end = false;
		memset(next, 0, sizeof(next));
	}

	void insert(string word)
	{
		Trie *node = this;
		for (int i = 0; i < word.length(); ++i)
		{
			if (node->next[word[i] - 'a'] == nullptr)
				node->next[word[i] - 'a'] = new Trie();
			node = node->next[word[i] - 'a'];
		}
		node->is_end = true;
	}

	bool search(string word)
	{
		Trie *node = this;
		for (int i = 0; i < word.length(); ++i)
		{
			node = node->next[word[i] - 'a'];
			if (node == nullptr)
				return false;
		}
		return node->is_end;
	}

	bool startsWith(string prefix)
	{
		Trie *node = this;
		for (int i = 0; i < prefix.length(); ++i)
		{
			node = node->next[prefix[i] - 'a'];
			if (node == nullptr)
				return false;
		}
		return true;
	}

private:
	bool is_end;
	Trie *next[26];
};

int main(int argc, char *argv[])
{
	Trie trie;
	return 0;
}
