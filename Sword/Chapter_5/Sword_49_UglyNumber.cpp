/**************************************************
	> File Name:  Sword_49_UglyNumber.cpp
	> Author:     Leuckart
	> Time:       2020-02-26 17:31
**************************************************/

// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。

#include <cassert>
#include <vector>
using namespace std;

int GetUglyNumber(int index)
{
	if (index == 0)
		return 0;

	vector<int> Ugly(index, 0);
	Ugly[0] = 1;

	int pos_2 = 0;
	int pos_3 = 0;
	int pos_5 = 0;

	for (size_t idx = 1; idx < index; ++idx)
	{
		Ugly[idx] = min(min(2 * Ugly[pos_2], 3 * Ugly[pos_3]), 5 * Ugly[pos_5]);

		while (Ugly[pos_2] * 2 <= Ugly[idx])
			++pos_2;
		while (Ugly[pos_3] * 3 <= Ugly[idx])
			++pos_3;
		while (Ugly[pos_5] * 5 <= Ugly[idx])
			++pos_5;
	}
	return Ugly[index - 1];
}

int main(int argc, char *argv[])
{
	assert(GetUglyNumber(1) == 1);
	assert(GetUglyNumber(2) == 2);
	assert(GetUglyNumber(3) == 3);
	assert(GetUglyNumber(4) == 4);
	assert(GetUglyNumber(5) == 5);
	assert(GetUglyNumber(6) == 6);
	assert(GetUglyNumber(7) == 8);
	assert(GetUglyNumber(8) == 9);
	assert(GetUglyNumber(9) == 10);
	assert(GetUglyNumber(10) == 12);
	assert(GetUglyNumber(11) == 15);

	assert(GetUglyNumber(1500) == 859963392);

	return 0;
}
