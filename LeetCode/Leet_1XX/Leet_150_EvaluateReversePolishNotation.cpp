/**************************************************
	> File Name:  Leet_150_EvaluateReversePolishNotation.cpp
	> Author:     Leuckart
	> Time:       2020-09-11 20:57
**************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
	int evalRPN(const vector<string> &tokens)
	{
		stack<int> S;
		for (int i = 0; i < tokens.size(); ++i)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				int b = S.top();
				S.pop();
				int a = S.top();
				S.pop();

				switch (tokens[i][0])
				{
				case '+':
					S.push(a + b);
					break;
				case '-':
					S.push(a - b);
					break;
				case '*':
					S.push(a * b);
					break;
				case '/':
					S.push(a / b);
					break;
				}
			}
			else
			{
				S.push(stoi(tokens[i]));
			}
		}
		return S.top();
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
