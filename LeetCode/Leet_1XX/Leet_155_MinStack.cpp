/**************************************************
	> File Name:  Leet_155_MinStack.cpp
	> Author:     Leuckart
	> Time:       2020-09-11 23:08
**************************************************/

#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
public:
	MinStack() {}

	void push(int x)
	{
		data_stack.push(x);
		if (min_stack.empty() || x < min_stack.top().first)
			min_stack.emplace(make_pair(x, data_stack.size()));
	}

	void pop()
	{
		if (data_stack.size() == min_stack.top().second)
			min_stack.pop();
		data_stack.pop();
	}

	int top()
	{
		return data_stack.top();
	}

	int getMin()
	{
		return min_stack.top().first;
	}

private:
	stack<int> data_stack;
	stack<pair<int, int>> min_stack;
};

int main(int argc, char *argv[])
{
	MinStack ms;
	return 0;
}
