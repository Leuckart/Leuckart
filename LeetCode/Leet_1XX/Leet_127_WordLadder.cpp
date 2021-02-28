/**************************************************
	> File Name:  Leet_127_WordLadder.cpp
	> Author:     Leuckart
	> Time:       2020-04-14 20:05
**************************************************/

#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int ladderLength(const string &beginWord, const string &endWord, const vector<string> &wordList)
	{
		unordered_set<string> dict(wordList.cbegin(), wordList.cend());
		if (dict.find(endWord) == dict.end())
			return 0;

		unordered_set<string> head;
		unordered_set<string> tail;
		head.insert(beginWord);
		tail.insert(endWord);

		int result = 2;
		while (!head.empty() && !tail.empty())
		{
			unordered_set<string> *pHead;
			unordered_set<string> *pTail;
			if (head.size() <= tail.size())
			{
				pHead = &head;
				pTail = &tail;
			}
			else
			{
				pHead = &tail;
				pTail = &head;
			}

			unordered_set<string> new_set;
			for (unordered_set<string>::const_iterator iter = pHead->cbegin(); iter != pHead->cend(); ++iter)
			{
				string word = *iter;
				for (int i = 0; i < beginWord.length(); ++i)
				{
					char ch = word[i];
					for (char c = 'a'; c <= 'z'; ++c)
					{
						word[i] = c;
						if (pTail->find(word) != pTail->end())
							return result;
						if (dict.find(word) != dict.end())
						{
							dict.erase(word);
							new_set.insert(word);
						}
					}
					word[i] = ch;
				}
			}
			++result;
			pHead->swap(new_set);
		}
		return 0;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
