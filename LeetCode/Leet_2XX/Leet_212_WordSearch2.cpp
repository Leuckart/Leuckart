/**************************************************
	> File Name:  Leet_212_WordSearch2.cpp
	> Author:     Leuckart
	> Time:       2020-09-25 22:14
**************************************************/

#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
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
			if (cur->char_map.count(word[i]) == 0)
				return false;
			cur = cur->char_map[word[i]];
		}
		return cur->exist;
	}

public:
	unordered_map<char, WordDictionary *> char_map;
	bool exist;
};

class Solution
{
public:
	vector<string> findWords(vector<vector<char>> &board, const vector<string> &words)
	{
		WordDictionary dict;
		for (int i = 0; i < words.size(); ++i)
			dict.addWord(words[i]);

		vector<string> result;
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j)
				DFS(board, i, j, &dict, result, "");
		return result;
	}

private:
	void DFS(vector<vector<char>> &board, const int row, const int col, WordDictionary *dict, vector<string> &result, string path)
	{
		char ch = board[row][col];

		if (row < 0 || row >= board.size() ||
			col < 0 || col >= board[0].size() ||
			dict->char_map[ch] == nullptr)
			return;

		path += ch;
		if (dict->exist)
			result.push_back(path);

		board[row][col] = '.';
		DFS(board, row - 1, col, dict->char_map[ch], result, "");
		DFS(board, row + 1, col, dict->char_map[ch], result, "");
		DFS(board, row, col - 1, dict->char_map[ch], result, "");
		DFS(board, row, col + 1, dict->char_map[ch], result, "");
		board[row][col] = ch;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
