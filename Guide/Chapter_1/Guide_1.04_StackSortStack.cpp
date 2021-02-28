/**************************************************
	> File Name:  Guide_1.04_StackSortStack.cpp
	> Author:     Leuckart
	> Time:       2020-10-02 05:22
**************************************************/

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
	static void sortStackByStack(stack<int> &st)
	{
		stack<int> help;
		while (!st.empty())
		{
			int cur = st.top();
			st.pop();

			while (!help.empty() && help.top() < cur)
			{
				st.push(help.top());
				help.pop();
			}
			help.push(cur);
		}

		while (!help.empty())
		{
			st.push(help.top());
			help.pop();
		}
	}
};

int main(int argc, char *argv[])
{
	stack<int> st;
	st.push(3);
	st.push(1);
	st.push(6);
	st.push(2);
	st.push(5);
	st.push(4);

	Solution::sortStackByStack(st);
	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
	return 0;
}
