/**************************************************
	> File Name:  Leet_168_ExcelSheetColumnTitle.cpp
	> Author:     Leuckart
	> Time:       2019-06-30 22:40
**************************************************/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string convertToTitle(int n)
	{
		string result = "";
		while (n > 0)
		{
			int div = n % 26;
			n /= 26;

			if (div == 0)
			{
				result += 'Z';
				n--;
			}
			else
				result += div + 'A' - 1;
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
