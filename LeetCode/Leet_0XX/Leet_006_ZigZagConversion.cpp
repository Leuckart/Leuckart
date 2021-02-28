/**************************************************
	> File Name:  Leet_006_ZigZagConversion.cpp
	> Author:     Leuckart
	> Time:       2019-04-17 21:43
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string convert(const string s, int numRows)
	{
		if (numRows == 1)
			return s;

		int period = 2 * numRows - 2;
		string ans(s.length(), 0);

		for (size_t row = 0, idx = 0; row < numRows; ++row)
		{
			if (row == 0 || row == numRows - 1)
			{
				for (size_t i = 0; i * period + row < s.length(); ++i)
					ans[idx++] = s[i * period + row];
			}
			else
			{
				for (size_t i = 0; i * period < s.length(); ++i)
				{
					if (i * period + row < s.length())
						ans[idx++] = s[i * period + row];
					if ((i + 1) * period - row < s.length())
						ans[idx++] = s[(i + 1) * period - row];
				}
			}
		}
		return ans;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
