/**************************************************
	> File Name:  Sword_33_SquenceOfBST.cpp
	> Author:     Leuckart
	> Time:       2020-02-18 18:05
**************************************************/

// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。

#include <cstdio>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

bool VerifyBSTRecursive(const vector<int> &vec, int beg, int end)
{
	if (beg >= end)
		return true;

	int rootValue = vec[end];
	int idx = beg;
	while (idx <= end && vec[idx] < rootValue)
		++idx;

	for (int i = idx; i < end; ++i)
		if (vec[i] < rootValue)
			return false;

	return VerifyBSTRecursive(vec, beg, idx - 1) &&
		   VerifyBSTRecursive(vec, idx, end - 1);
}

bool VerifyBST(const vector<int> &vec)
{
	if (vec.empty())
		return true;
	return VerifyBSTRecursive(vec, 0, vec.size() - 1);
}

int main(int argc, char *argv[])
{
	assert(VerifyBST({4, 8, 6, 12, 16, 14, 10}) == true);
	assert(VerifyBST({4, 6, 7, 5}) == true);
	assert(VerifyBST({1, 2, 3, 4, 5}) == true);
	assert(VerifyBST({5, 4, 3, 2, 1}) == true);
	assert(VerifyBST({5}) == true);
	assert(VerifyBST({7, 4, 6, 5}) == false);
	assert(VerifyBST({4, 6, 12, 8, 16, 14, 10}) == false);

	return 0;
}
