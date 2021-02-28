/**************************************************
	> File Name:  Leet_068_TextJustification.cpp
	> Author:     Leuckart
	> Time:       2019-07-21 01:23
**************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> fullJustify(const vector<string> &words, const int maxWidth)
	{
		vector<string> result;
		for (int idx = 0; idx < words.size();)
		{
			int word_num = 0;
			int line_size = 0;
			while (idx + word_num < words.size() &&
				   line_size + word_num + words[idx + word_num].size() <= maxWidth)
			{
				line_size += words[idx + word_num].size();
				++word_num;
			}

			string cur_line = words[idx];
			// 未到达最后一行
			if (idx + word_num < words.size())
			{
				for (int i = 1; i < word_num; ++i)
				{
					int space_num = (maxWidth - line_size) / (word_num - 1);
					if (i <= (maxWidth - line_size) % (word_num - 1))
						++space_num;
					cur_line += string(space_num, ' ') + words[idx + i];
				}
			}
			else
			{
				for (int i = 1; i < word_num; ++i)
					cur_line += " " + words[idx + i];
			}

			cur_line += string(maxWidth - cur_line.size(), ' ');
			result.push_back(cur_line);
			idx += word_num;
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
