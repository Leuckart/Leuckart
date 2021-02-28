/**************************************************
	> File Name:  Leet_151_ReverseWordsInAString.cpp
	> Author:     Leuckart
	> Time:       2020-04-17 03:02
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string reverseWords(const string s)
	{
		if (s.empty())
			return "";

		string result;
		int index = s.length() - 1;

		bool flag = true;
		while (index >= 0)
		{
			while (index >= 0 && s[index] == ' ')
				--index;
			int end = index;

			if (index < 0)
				break;

			if (!flag)
				result += " ";

			while (index >= 0 && s[index] != ' ')
				--index;
			int beg = index + 1;

			result += s.substr(beg, end - beg + 1);
			flag = false;
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
