/**************************************************
	> File Name:  Guide_4.16_NumberToLetter.cpp
	> Author:     Leuckart
	> Time:       2020-10-08 17:32
**************************************************/

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	static int getNumber(const string &str)
	{
		if (str.length() < 2)
			return isChar(str);

		// dp[i] : str[0:i]的字母组合种数
		vector<int> dp(str.length(), 0);
		dp[0] = isChar(str.substr(0, 1));
		dp[1] = isChar(str.substr(0, 2)) +
				(isChar(str.substr(0, 1)) && isChar(str.substr(1, 1)));

		for (int i = 2; i < str.length(); ++i)
			dp[i] = dp[i - 2] * isChar(str.substr(i - 1, 2)) +
					dp[i - 1] * isChar(str.substr(i, 1));

		return dp.back();
	}

private:
	static bool isChar(const string &str)
	{
		int num = stoi(str);
		return num >= 1 && num <= 26 && str[0] != '0';
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::getNumber("781231783161018231") == 48);
	return 0;
}
