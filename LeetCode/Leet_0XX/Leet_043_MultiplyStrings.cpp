/**************************************************
	> File Name:  Leet_043_MultiplyStrings.cpp
	> Author:     Leuckart
	> Time:       2019-06-30 21:38
**************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	string multiply(const string &num1, const string &num2)
	{
		if (num1.length() < num2.length())
			return multiply(num2, num1);

		vector<string> lookUp(10);
		for (int mult = 1; mult < 10; ++mult)
		{
			string str;
			int flag = 0;
			for (int i = num1.length() - 1; i >= 0; --i)
			{
				int tmp = mult * (num1[i] - '0') + flag;
				flag = tmp / 10;
				str.push_back(tmp % 10 + '0');
			}
			if (flag != 0)
				str.push_back(flag + '0');
			lookUp[mult] = str;
		}

		string ans = "0";
		for (int i = 0; i < num2.length(); ++i)
		{
			string tmp = string(i, '0') + lookUp[num2[num2.length() - 1 - i] - '0'];
			int flag = 0;
			for (int j = 0; j < tmp.length(); ++j)
			{
				if (j < ans.length())
				{
					int sum = ans[j] - '0' + tmp[j] - '0' + flag;
					ans[j] = sum % 10 + '0';
					flag = sum / 10;
				}
				else
				{
					int sum = tmp[j] - '0' + flag;
					ans.push_back(sum % 10 + '0');
					flag = sum / 10;
				}
			}
			if (flag != 0)
				ans.push_back(flag + '0');
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
