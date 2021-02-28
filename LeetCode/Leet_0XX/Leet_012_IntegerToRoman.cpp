/**************************************************
	> File Name:  Leet_012_IntegerToRoman.cpp
	> Author:     Leuckart
	> Time:       2019-06-12 20:24
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	string intToRoman(int num)
	{
		string ans;
		for (int i = 0; i < values.size(); ++i)
		{
			while (num >= values[i])
			{
				num -= values[i];
				ans.append(strs[i]);
			}
		}
		return ans;
	}

private:
	const vector<int> values{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	const vector<string> strs{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
