/**************************************************
	> File Name:  Leet_125_ValidPalindrome.cpp
	> Author:     Leuckart
	> Time:       2020-04-14 16:29
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	bool isPalindrome(const string &s)
	{
		int lhs = 0;
		int rhs = s.length() - 1;

		while (lhs < rhs)
		{
			while (lhs < rhs && !isValidCharacter(s[lhs]))
				++lhs;
			while (lhs < rhs && !isValidCharacter(s[rhs]))
				--rhs;

			if (lhs >= rhs)
				return true;
			if (!isEqualCharacter(s[lhs], s[rhs]))
				return false;

			++lhs;
			--rhs;
		}
		return lhs >= rhs;
	}

private:
	bool isValidCharacter(const char ch)
	{
		return (ch >= '0' && ch <= '9') ||
			   (ch >= 'a' && ch <= 'z') ||
			   (ch >= 'A' && ch <= 'Z');
	}

	bool isEqualCharacter(const char ch1, const char ch2)
	{
		if (ch1 >= '0' && ch1 <= '9' && ch1 == ch2)
			return true;
		if (ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'a' && ch2 <= 'z' && ch1 == ch2)
			return true;
		if (ch1 >= 'A' && ch1 <= 'Z' && ch2 >= 'A' && ch2 <= 'Z' && ch1 == ch2)
			return true;
		if (ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'A' && ch2 <= 'Z' && ch1 - 'a' == ch2 - 'A')
			return true;
		if (ch1 >= 'A' && ch1 <= 'Z' && ch2 >= 'a' && ch2 <= 'z' && ch1 - 'A' == ch2 - 'a')
			return true;
		return false;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
