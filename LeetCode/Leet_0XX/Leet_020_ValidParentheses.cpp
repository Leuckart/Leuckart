/**************************************************
	> File Name:  Leet_020_ValidParentheses.cpp
	> Author:     Leuckart
	> Time:       2019-04-12 15:48
**************************************************/

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
	bool isValid(const string s)
	{
		stack<char> S;
		for (int i = 0; i < s.length(); ++i)
		{
			if (!S.empty() && (s[i] - S.top() == 1 || s[i] - S.top() == 2))
				S.pop();
			else
				S.push(s[i]);
		}
		return S.empty();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
