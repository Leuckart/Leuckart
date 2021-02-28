/**************************************************
	> File Name:   template.cpp
	> Author:      Leuckart
	> Time:        2017-09-23  03:26
**************************************************/

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

template <typename T>
void show(const T &obj, const string &str = "Object")
{
	cout << str << ":    ";
	for (auto &i : obj)
		cout << i << " ";
	cout << endl;
}

vector<string> split(const string &str, const char delim = ' ')
{
	vector<string> result;
	for (int idx = 0; idx < str.length();)
	{
		int go = idx;
		while (go < str.length() && str[go] != delim)
			++go;

		if (idx != go)
			result.push_back(str.substr(idx, go - idx));
		idx = go + 1;
	}
	return result;
}

class Singleton
{
private:
	Singleton(){};
	Singleton(const Singleton &) = delete;
	Singleton &operator=(const Singleton &) = delete;

public:
	static Singleton &getInstance()
	{
		static Singleton instance;
		return instance;
	}
};

class A
{
public:
	virtual void show() = 0;
	void func()
	{
		show();
	}
};

class B : public A
{
public:
	void show() override
	{
		cout << "B" << endl;
	}
};

class C : public B
{
public:
	void show()
	{
		cout << "C" << endl;
	}
};

int main(int argc, char *argv[])
{
	int a = 0x1234;
	char *p = (char *)&a;
	cout << int(*p) << endl;
	cout << int(*(p + 1)) << endl;
	cout << int(*(p + 2)) << endl;
	cout << int(*(p + 3)) << endl;

	B b;
	C c;
	b.func();
	c.func();

	// int b = (int)(((int *)0) + 4);
	//int b = reinterpret_cast<int>(((int *)0) + 4);
	//cout << b << endl;

	return 0;
}

/*
5 2
1 3 5 7 9
*/
