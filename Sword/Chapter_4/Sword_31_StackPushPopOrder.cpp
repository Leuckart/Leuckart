/**************************************************
	> File Name:  Sword_31_StackPushPopOrder.cpp
	> Author:     Leuckart
	> Time:       2020-02-18 13:47
**************************************************/

// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
using namespace std;

bool IsPopOrder(vector<int> vPush, vector<int> vPop)
{
	if (vPush.empty() && vPop.empty())
		return true;
	if (vPush.size() != vPop.size())
		return false;

	size_t iPush = 0;
	size_t iPop = 0;
	size_t len = vPush.size();

	stack<int> data;
	while (iPop < len)
	{
		while (data.empty() || (iPush < len && data.top() != vPop[iPop]))
		{
			data.push(vPush[iPush]);
			++iPush;
		}

		if (data.top() != vPop[iPop])
			break;

		data.pop();
		++iPop;
	}
	return iPop == len;
}

int main(int argc, char *argv[])
{
	assert(IsPopOrder({1, 2, 3, 4, 5}, {4, 5, 3, 2, 1}) == true);
	assert(IsPopOrder({1, 2, 3, 4, 5}, {3, 5, 4, 2, 1}) == true);
	assert(IsPopOrder({1, 2, 3, 4, 5}, {4, 3, 5, 1, 2}) == false);
	assert(IsPopOrder({1, 2, 3, 4, 5}, {3, 5, 4, 1, 2}) == false);
	assert(IsPopOrder({1}, {2}) == false);
	assert(IsPopOrder({1}, {1}) == true);
	assert(IsPopOrder({}, {}) == true);

	return 0;
}
