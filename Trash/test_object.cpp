/**************************************************
	> File Name:  test_object.cpp
	> Author:     Leuckart
	> Time:       2020-03-17 02:17
**************************************************/

#include <iostream>
using namespace std;

class X
{
public:
	int a;
};

class Y : public virtual X
{
};

class Z : public virtual X
{
};

class A : public Y, public Z
{
};

//

class H
{
	int h;
	char h2;
	char h3;
};

class I : public H
{
	char i;
};

class J : public I
{
	char j;
};

class K : public J
{
	char k;
};

int main()
{
	cout << sizeof(X) << endl;
	cout << sizeof(Y) << endl;
	cout << sizeof(Z) << endl;
	cout << sizeof(A) << endl;
	cout << &X::a << endl;

	cout << "H:\t" << sizeof(H) << endl;
	cout << "I:\t" << sizeof(I) << endl;
	cout << "J:\t" << sizeof(J) << endl;
	cout << "K:\t" << sizeof(K) << endl;

	return 0;
}
