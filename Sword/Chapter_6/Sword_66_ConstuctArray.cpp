/**************************************************
	> File Name:  Sword_66_ConstuctArray.cpp
	> Author:     Leuckart
	> Time:       2020-02-28 04:22
**************************************************/

// 面试题66：构建乘积数组
// 题目：给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其
// 中B中的元素B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

#include <cassert>
#include <vector>
using namespace std;

vector<int> ConstructArray(const vector<int> &input)
{
	if (input.empty())
		return {};

	vector<int> output(input.size(), 0);
	vector<int> lhs(input.size(), 0);
	vector<int> rhs(input.size(), 0);

	lhs[0] = 1;
	for (int i = 1; i < input.size(); ++i)
		lhs[i] = lhs[i - 1] * input[i - 1];

	rhs[input.size() - 1] = 1;
	for (int i = input.size() - 2; i >= 0; --i)
		rhs[i] = rhs[i + 1] * input[i + 1];

	for (int i = 0; i < input.size(); ++i)
		output[i] = lhs[i] * rhs[i];
	return output;
}

bool beSame(vector<int> vec1, vector<int> vec2)
{
	if (vec1.size() != vec2.size())
		return false;

	for (size_t i = 0; i < vec1.size(); ++i)
		if (vec1[i] != vec2[i])
			return false;
	return true;
}

int main(int argc, char *argv[])
{
	assert(beSame(ConstructArray({1, 2, 3, 4, 5}), {120, 60, 40, 30, 24}));
	assert(beSame(ConstructArray({1, 2, 0, 4, 5}), {0, 0, 40, 0, 0}));
	assert(beSame(ConstructArray({1, 2, 0, 4, 0}), {0, 0, 0, 0, 0}));
	assert(beSame(ConstructArray({1, -2, 3, -4, 5}), {120, -60, 40, -30, 24}));
	assert(beSame(ConstructArray({1, -2}), {-2, 1}));

	return 0;
}
