/**************************************************
	> File Name:  Leet_030_SubstringsWithConcatenation.cpp
	> Author:     Leuckart
	> Time:       2019-07-02 15:57
**************************************************/

#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<int> findSubstring(const string s, const vector<string> &words)
	{
		if (s.empty() || words.empty())
			return {};

		unordered_map<string, int> dict;
		for (int i = 0; i < words.size(); ++i)
			dict[words[i]]++;

		vector<int> ans;
		const int word_size = words[0].length();
		for (int i = 0; i < word_size; ++i)
		{
			int count = 0, beg = i;
			unordered_map<string, int> current;
			for (int j = i; j + word_size <= s.length(); j += word_size)
			{
				string tmp = s.substr(j, word_size);

				// 当前 tmp 不在 words 中
				if (dict.find(tmp) == dict.end())
				{
					current.clear();
					count = 0;
					beg = j + word_size;
					continue;
				}

				// tmp 已经满了
				while (current[tmp] == dict[tmp])
				{
					current[s.substr(beg, word_size)]--;
					beg += word_size;
					count--;
				}
				current[tmp]++;
				count++;

				if (count == words.size())
				{
					ans.push_back(beg);
					current[s.substr(beg, word_size)]--;
					beg += word_size;
					count--;
				}
			}
		}
		return ans;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
