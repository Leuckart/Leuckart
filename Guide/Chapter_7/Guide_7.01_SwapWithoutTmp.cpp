/**************************************************
	> File Name:  Guide_7.01_SwapWithoutTmp.cpp
	> Author:     Leuckart
	> Time:       2020-03-26 22:44
**************************************************/

#include <iostream>
using namespace std;

void my_swap(int &x, int &y)
{
	x ^= y;
	y ^= x;
	x ^= y;
}

int main(int argc, char *argv[])
{
	int x = -16;
	int y = 111;
	cout << x << "\t" << y << endl;

	my_swap(x, y);
	cout << x << "\t" << y << endl;
	return 0;
}
