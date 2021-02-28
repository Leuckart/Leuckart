/**************************************************
	> File Name:  Guide_1.03_ReverseStackUsingRecursive.cpp
	> Author:     Leuckart
	> Time:       2020-03-30 01:39
**************************************************/

#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

class Solution
{
public:
	static void reverse(stack<int> &st)
	{
		if (st.empty())
			return;

		int ret = getBottomElement(st);
		reverse(st);
		st.push(ret);
	}

private:
	// 移除并返回栈底元素
	static int getBottomElement(stack<int> &st)
	{
		int result = st.top();
		st.pop();

		if (st.empty())
			return result;
		else
		{
			int ret = getBottomElement(st);
			st.push(result);
			return ret;
		}
	}
};

int main(int argc, char *argv[])
{
	stack<int> st;
	for (int i = 0; i < 10; ++i)
		st.push(i);

	Solution::reverse(st);
	for (int i = 0; i < 10; ++i, st.pop())
		assert(st.top() == i);

	return 0;
}
