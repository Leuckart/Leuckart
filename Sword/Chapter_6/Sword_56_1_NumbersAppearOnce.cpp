/**************************************************
	> File Name:  Sword_56_1_NumbersAppearOnce.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 04:37
**************************************************/

// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
// 找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

#include <cassert>
#include <vector>
using namespace std;

void FindNumAppearOnce(const vector<int> &data, int &num1, int &num2)
{
	if (data.size() < 2)
		return;

	int total = 0;
	for (size_t i = 0; i < data.size(); ++i)
		total ^= data[i];

	int mask = 1;
	while ((total & mask) == 0)
		mask <<= 1;

	num1 = num2 = 0;
	for (size_t i = 0; i < data.size(); ++i)
	{
		if (data[i] & mask)
			num1 ^= data[i];
		else
			num2 ^= data[i];
	}
}

int main(int argc, char *argv[])
{
	int num1 = 0, num2 = 0;

	FindNumAppearOnce({2, 4, 3, 6, 3, 2, 5, 5}, num1, num2);
	assert((num1 == 4 && num2 == 6) || (num1 == 6 && num2 == 4));

	FindNumAppearOnce({4, 6}, num1, num2);
	assert((num1 == 4 && num2 == 6) || (num1 == 6 && num2 == 4));

	FindNumAppearOnce({4, 6, 1, 1, 1, 1}, num1, num2);
	assert((num1 == 4 && num2 == 6) || (num1 == 6 && num2 == 4));

	return 0;
}
