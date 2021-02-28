/**************************************************
	> File Name:  Guide_1.01_GetMinStack.cpp
	> Author:     Leuckart
	> Time:       2020-02-28 16:14
**************************************************/

#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

class MyStack
{
public:
	MyStack() {}

	void push(const int val)
	{
		stackData.push(val);

		if (stackMin.empty() || val <= stackMin.top())
			stackMin.push(val);
	}

	int pop()
	{
		if (stackData.empty())
			throw runtime_error("Stack empty");

		int ret = stackData.top();
		stackData.pop();

		if (ret == stackMin.top())
			stackMin.pop();
		return ret;
	}

	int getmin()
	{
		if (stackMin.empty())
			throw runtime_error("Stack empty");
		return stackMin.top();
	}

private:
	stack<int> stackData; // 保存当前栈中的元素
	stack<int> stackMin;  // 保存每一步的最小值
};

int main(int argc, char *argv[])
{
	MyStack ms;
	ms.push(3);
	assert(ms.getmin() == 3);
	ms.push(4);
	assert(ms.getmin() == 3);

	ms.push(1);
	assert(ms.getmin() == 1);
	assert(ms.pop() == 1);
	assert(ms.getmin() == 3);

	return 0;
}
