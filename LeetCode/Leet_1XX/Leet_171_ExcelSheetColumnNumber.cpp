/**************************************************
	> File Name:  LeetCode_171_ExcelSheetColumnNumber.cpp
	> Author:     Leuckart
	> Time:       2019-07-18 22:56
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int titleToNumber(const string s)
	{
		int result = 0;
		for (int i = 0; i < s.length(); ++i)
			result = result * 26 + (s[i] - 'A' + 1);
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
