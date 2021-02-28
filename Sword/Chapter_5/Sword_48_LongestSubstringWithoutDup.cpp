/**************************************************
	> File Name:  Sword_48_LongestSubstringWithoutDup.cpp
	> Author:     Leuckart
	> Time:       2020-02-26 16:11
**************************************************/

// 面试题48：最长不含重复字符的子字符串
// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
// 字符串的长度。假设字符串中只包含从'a'到'z'的字符。

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

int maxSubstring(const string &str)
{
	int cur_len = 0;
	int max_len = 0;
	vector<int> position(26, -1);

	for (size_t idx = 0; idx < str.length(); ++idx)
	{
		if (position[str[idx] - 'a'] == -1)
		{
			++cur_len;
		}
		else
		{
			int distance = idx - position[str[idx] - 'a'];
			if (distance > cur_len)
				++cur_len;
			else
				cur_len = distance;
		}

		position[str[idx] - 'a'] = idx;
		if (cur_len > max_len)
			max_len = cur_len;
	}
	return max_len;
}

int main(int argc, char *argv[])
{
	assert(maxSubstring("abcacfrar") == 4);
	assert(maxSubstring("acfrarabc") == 4);
	assert(maxSubstring("arabcacfr") == 4);
	assert(maxSubstring("aaaa") == 1);
	assert(maxSubstring("abcdefg") == 7);
	assert(maxSubstring("aaabbbccc") == 2);
	assert(maxSubstring("abcdcba") == 4);
	assert(maxSubstring("abcdaef") == 6);
	assert(maxSubstring("a") == 1);
	assert(maxSubstring("") == 0);

	return 0;
}
