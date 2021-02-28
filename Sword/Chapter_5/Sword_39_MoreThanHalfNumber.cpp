/**************************************************
	> File Name:  Sword_39_MoreThanHalfNumber.cpp
	> Author:     Leuckart
	> Time:       2020-02-19 16:15
**************************************************/

// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
// 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
// 出现了5次，超过数组长度的一半，因此输出2。

#include <cstdio>
#include "../Inc/Sword_Array.h"

bool CheckMoreThanHalf(std::vector<int> nums, int num)
{
	int times = 0;
	for (int i = 0; i < nums.size(); ++i)
		if (nums[i] == num)
			++times;
	return times > nums.size() / 2;
}

// ====================方法1====================
int MoreThanHalf_Solution1(std::vector<int> nums)
{
	if (nums.empty())
		return -1;

	int mid = nums.size() / 2;
	int start = 0;
	int end = nums.size() - 1;
	int index = Partition(nums, start, end);

	while (index != mid)
	{
		if (index > mid)
		{
			end = index - 1;
			index = Partition(nums, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(nums, start, end);
		}
	}

	int result = nums[mid];
	if (!CheckMoreThanHalf(nums, result))
		result = -1;

	return result;
}

// ====================方法2====================
int MoreThanHalf_Solution2(std::vector<int> nums)
{
	if (nums.empty())
		return -1;

	int ans = nums[0];
	int times = 1;

	for (size_t i = 1; i < nums.size(); ++i)
	{
		if (times == 0)
		{
			++times;
			ans = nums[i];
		}
		else if (nums[i] == ans)
			++times;
		else
			--times;
	}

	times = 0;
	for (size_t i = 0; i < nums.size(); ++i)
		if (nums[i] == ans)
			++times;

	if (times < nums.size() / 2)
		return -1;
	else
		return ans;
}

// ====================测试代码====================
void Test(const char *testName, const std::vector<int> numbers, int expectedValue)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);
	std::vector<int> copy = numbers;

	printf("Test for solution1: ");
	int result = MoreThanHalf_Solution1(numbers);
	if (result == expectedValue)
		printf("Passed.\n");
	else
		printf("Failed.\n");

	printf("Test for solution2: ");
	result = MoreThanHalf_Solution2(copy);
	if (result == expectedValue)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 存在出现次数超过数组长度一半的数字
void Test1()
{
	Test("Test1", {1, 2, 3, 2, 2, 2, 5, 4, 2}, 2);
}

// 不存在出现次数超过数组长度一半的数字
void Test2()
{
	int numbers[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
	Test("Test2", {1, 2, 3, 2, 4, 2, 5, 2, 3}, -1);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3()
{
	Test("Test3", {2, 2, 2, 2, 2, 1, 3, 4, 5}, 2);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test4()
{
	Test("Test4", {1, 3, 4, 5, 2, 2, 2, 2, 2}, 2);
}

// 输入
void Test5()
{
	Test("Test5", {1}, 1);
}

int main(int argc, char *argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}
