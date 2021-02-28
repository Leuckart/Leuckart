/**************************************************
	> File Name:  Leet_093_RestoreIPAddresses.cpp
	> Author:     Leuckart
	> Time:       2019-07-29 13:28
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> restoreIpAddresses(const string s)
	{
		vector<string> result;
		for (int a = 1; a <= 3; a++)
		{
			for (int b = 1; b <= 3; b++)
			{
				for (int c = 1; c <= 3; c++)
				{
					for (int d = 1; d <= 3; d++)
					{
						if ((a + b + c + d != s.length()) ||
							(a > 1 && s[0] == '0') ||
							(b > 1 && s[a] == '0') ||
							(c > 1 && s[a + b] == '0') ||
							(d > 1 && s[a + b + c] == '0'))
							continue;

						int A = stoi(s.substr(0, a));
						int B = stoi(s.substr(a, b));
						int C = stoi(s.substr(a + b, c));
						int D = stoi(s.substr(a + b + c, d));

						if (A <= 255 && B <= 255 && C <= 255 && D <= 255)
							result.push_back(to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D));
					}
				}
			}
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
