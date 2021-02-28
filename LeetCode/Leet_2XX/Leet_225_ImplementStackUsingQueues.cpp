/**************************************************
	> File Name:  Leet_225_ImplementStackUsingQueues.cpp
	> Author:     Leuckart
	> Time:       2020-09-23 22:59
**************************************************/

#include <queue>
using namespace std;

class MyStack
{
public:
	MyStack() {}

	void push(int x)
	{
		Q.push(x);
	}

	int pop()
	{
		for (int i = 0; i < Q.size() - 1; ++i)
		{
			Q.push(Q.front());
			Q.pop();
		}

		int ret = Q.front();
		Q.pop();
		return ret;
	}

	int top()
	{
		for (int i = 0; i < Q.size() - 1; ++i)
		{
			Q.push(Q.front());
			Q.pop();
		}

		int ret = Q.front();
		Q.push(Q.front());
		Q.pop();
		return ret;
	}

	bool empty()
	{
		return Q.empty();
	}

private:
	queue<int> Q;
};

int main(int argc, char *argv[])
{
	MyStack ms;
	return 0;
}
