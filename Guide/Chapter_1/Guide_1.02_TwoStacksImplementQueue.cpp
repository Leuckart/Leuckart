/**************************************************
	> File Name:  Guide_1.02_TwoStacksImplementQueue.cpp
	> Author:     Leuckart
	> Time:       2020-03-26 14:06
**************************************************/

#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

class My_Queue
{
public:
	My_Queue() {}

	void push(const int val)
	{
		stackPush.push(val);
		pushToPop();
	}

	int pop()
	{
		if (stackPop.empty() && stackPush.empty())
			throw runtime_error("Queue empty");

		pushToPop();
		int ret = stackPop.top();
		stackPop.pop();
		return ret;
	}

	int front()
	{
		if (stackPop.empty() && stackPush.empty())
			throw runtime_error("Queue empty");

		pushToPop();
		return stackPop.top();
	}

private:
	void pushToPop()
	{
		if (stackPop.empty())
		{
			while (!stackPush.empty())
			{
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
	}

private:
	stack<int> stackPush;
	stack<int> stackPop;
};

int main(int argc, char *argv[])
{
	My_Queue mq;
	mq.push(1);
	mq.push(2);
	mq.push(3);

	assert(mq.front() == 1);
	assert(mq.pop() == 1);
	assert(mq.front() == 2);
	assert(mq.pop() == 2);
	assert(mq.front() == 3);
	assert(mq.pop() == 3);

	return 0;
}
