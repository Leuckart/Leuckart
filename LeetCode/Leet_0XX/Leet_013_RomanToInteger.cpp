/**************************************************
	> File Name:  Leet_013_RomanToInteger.cpp
	> Author:     Leuckart
	> Time:       2019-04-11 18:30
**************************************************/

#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int romanToInt(const string s)
	{
		int ans = 0;
		for (int i = 0; i < s.length() - 1; ++i)
		{
			if (values.find(s[i])->second < values.find(s[i + 1])->second)
				ans -= values.find(s[i])->second;
			else
				ans += values.find(s[i])->second;
		}
		return ans + values.find(s.back())->second;
	}

private:
	const unordered_map<char, int> values{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
