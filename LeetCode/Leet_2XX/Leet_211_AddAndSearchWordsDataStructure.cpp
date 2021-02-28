/**************************************************
	> File Name:  Leet_211_AddAndSearchWordsDataStructure.cpp
	> Author:     Leuckart
	> Time:       2020-09-25 19:40
**************************************************/

#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

class WordDictionary
{
public:
	WordDictionary()
	{
		char_map.clear();
		exist = false;
	}

	void addWord(const string &word)
	{
		WordDictionary *cur = this;
		for (int i = 0; i < word.length(); ++i)
		{
			if (cur->char_map.count(word[i]) == 0)
				cur->char_map[word[i]] = new WordDictionary();
			cur = cur->char_map[word[i]];
		}
		cur->exist = true;
	}

	bool search(const string &word)
	{
		WordDictionary *cur = this;
		for (int i = 0; i < word.length(); ++i)
		{
			if (word[i] == '.')
			{
				bool result = false;
				for (unordered_map<char, WordDictionary *>::const_iterator iter = cur->char_map.cbegin(); iter != cur->char_map.cend(); ++iter)
					result |= iter->second->search(word.substr(i + 1));
				return result;
			}
			else
			{
				if (cur->char_map.count(word[i]) == 0)
					return false;
				cur = cur->char_map[word[i]];
			}
		}
		return cur->exist;
	}

private:
	unordered_map<char, WordDictionary *> char_map;
	bool exist;
};

int main(int argc, char *argv[])
{
	WordDictionary wd;

	wd.addWord("bad");
	wd.addWord("dad");
	wd.addWord("mad");

	cout << wd.search("pad") << endl;
	cout << wd.search("bad") << endl;
	cout << wd.search(".ad") << endl;
	cout << wd.search("b..") << endl;
	return 0;
}
