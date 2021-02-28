/**************************************************
	> File Name:  Sword_45_SortArrayForMinNumber.cpp
	> Author:     Leuckart
	> Time:       2020-02-26 02:20
**************************************************/

// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
// 接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
// 字能排成的最小数字321323。

#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool lessThan(const string &s1, const string &s2)
{
	return s1 + s2 < s2 + s1;
}

string GetMinNumber(vector<int> vec)
{
	if (vec.empty())
		return "";

	vector<string> strs;
	for (size_t i = 0; i < vec.size(); ++i)
		strs.push_back(to_string(vec[i]));

	sort(strs.begin(), strs.end(), lessThan);

	string result;
	for (size_t i = 0; i < strs.size(); ++i)
		result += strs[i];
	return result;
}

int main(int argc, char *argv[])
{
	assert(GetMinNumber({3, 5, 1, 4, 2}) == "12345");
	assert(GetMinNumber({3, 32, 321}) == "321323");
	assert(GetMinNumber({3, 323, 32123}) == "321233233");
	assert(GetMinNumber({1, 11, 111}) == "111111");
	assert(GetMinNumber({321}) == "321");
	assert(GetMinNumber({}) == "");

	return 0;
}
