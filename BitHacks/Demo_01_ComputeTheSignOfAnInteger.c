/**************************************************
	> File Name:  Demo_01_ComputeTheSignOfAnInteger.c
	> Author:     Leuckart
	> Time:       2020-03-16 03:02
**************************************************/

#include <stdio.h>
#define CHAR_BIT 8

int core_1(int v)
{
	int sign = (v > 0) - (v < 0);
	return sign;
}

int core_2(int v)
{
	int sign = (v != 0) |
			   -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));
	return sign;
}

int core_3(int v)
{
	int sign = (v != 0) |
			   (v >> (sizeof(int) * CHAR_BIT - 1));
	return sign;
}

int main(int argc, char *argv[])
{
	int v;
	core_1(-12);
	core_2(-12);
	core_3(-12);

	return 0;
}
