/**************************************************
	> File Name:  Sword_09_QueueWithTwoStacks.cpp
	> Author:     Leuckart
	> Time:       2020-02-16 01:26
**************************************************/

// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

#include <stdio.h>
#include <stack>
#include <exception>
using namespace std;

template <typename T>
class CQueue
{
public:
	CQueue(){};
	~CQueue(){};

	void appendTail(const T &node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T &element)
{
	stack1.push(element);
}

template <typename T>
T CQueue<T>::deleteHead()
{
	if (!stack2.empty())
	{
		T t = stack2.top();
		stack2.pop();
		return t;
	}
	else
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		return deleteHead();
	}
}

// ====================测试代码====================
void Test(char actual, char expected)
{
	if (actual == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(int argc, char *argv[])
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test(head, 'a');

	head = queue.deleteHead();
	Test(head, 'b');

	queue.appendTail('d');
	head = queue.deleteHead();
	Test(head, 'c');

	queue.appendTail('e');
	head = queue.deleteHead();
	Test(head, 'd');

	head = queue.deleteHead();
	Test(head, 'e');

	return 0;
}
