/**************************************************
	> File Name:  Sword_30_MinInStack.cpp
	> Author:     Leuckart
	> Time:       2020-02-18 13:22
**************************************************/

// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。

#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

template <typename T>
class StackWithMin
{
public:
	StackWithMin() {}
	~StackWithMin() {}

	bool empty() const { return m_data.empty(); }
	size_t size() const { return m_data.size(); }
	T &top() { return m_data.top(); }

	const T &min() const;
	void push(const T &value);
	void pop();

private:
	stack<T> m_data; // 数据栈，存放栈的所有元素
	stack<T> m_min;  // 辅助栈，存放栈的最小元素
};

template <typename T>
const T &StackWithMin<T>::min() const
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	return m_min.top();
}

template <typename T>
void StackWithMin<T>::push(const T &value)
{
	m_data.push(value);

	if (m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template <typename T>
void StackWithMin<T>::pop()
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	m_data.pop();
	m_min.pop();
}

void Test(const char *testName, const StackWithMin<int> &stack, int expected)
{
	if (testName != nullptr)
		cout << testName << " begins: ";

	if (stack.min() == expected)
		cout << "Passed." << endl;
	else
		cout << "Failed." << endl;
}

int main(int argc, char *argv[])
{
	StackWithMin<int> stack;

	stack.push(3);
	Test("Test1", stack, 3);

	stack.push(4);
	Test("Test2", stack, 3);

	stack.push(2);
	Test("Test3", stack, 2);

	stack.push(3);
	Test("Test4", stack, 2);

	stack.pop();
	Test("Test5", stack, 2);

	stack.pop();
	Test("Test6", stack, 3);

	stack.pop();
	Test("Test7", stack, 3);

	stack.push(0);
	Test("Test8", stack, 0);

	return 0;
}
