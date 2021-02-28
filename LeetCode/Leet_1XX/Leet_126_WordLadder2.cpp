/**************************************************
	> File Name:  Leet_126_WordLadder2.cpp
	> Author:     Leuckart
	> Time:       2020-04-15 00:56
**************************************************/

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	vector<vector<string>> findLadders(const string beginWord, const string endWord, const vector<string> &wordList)
	{
		unordered_set<string> dict(wordList.cbegin(), wordList.cend());
		if (dict.find(endWord) == dict.end())
			return {};

		vector<vector<string>> result;
		vector<string> path;

		unordered_map<string, vector<string>> neighbor;
		unordered_map<string, int> depth;
		depth[beginWord] = 1;

		queue<string> Q;
		Q.push(beginWord);

		while (!Q.empty())
		{
			string cur = Q.front();
			Q.pop();

			for (int i = 0; i < cur.size(); ++i)
			{
				string tmp = cur;
				for (char c = 'a'; c <= 'z'; ++c)
				{
					tmp[i] = c;
					if (dict.count(tmp))
					{
						if (depth.count(tmp) == 0)
						{
							Q.push(tmp);
							depth[tmp] = depth[cur] + 1;
							neighbor[tmp].push_back(cur);
						}
						else if (depth[tmp] == depth[cur] + 1)
						{
							neighbor[tmp].push_back(cur);
						}
					}
				}
			}
		}
		DFS(beginWord, endWord, path, neighbor, result);
		return result;
	}

private:
	void DFS(const string &beginword, const string &curr, vector<string> path,
			 unordered_map<string, vector<string>> &neighbor, vector<vector<string>> &result)
	{
		if (curr == beginword)
		{
			path.push_back(curr);
			reverse(path.begin(), path.end());
			result.push_back(path);
			return;
		}

		path.push_back(curr);
		for (string word : neighbor[curr])
			DFS(beginword, word, path, neighbor, result);
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
