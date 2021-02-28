/**************************************************
	> File Name:  Leet_087_ScrambleString.cpp
	> Author:     Leuckart
	> Time:       2019-07-25 17:45
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	bool isScramble(string s1, string s2)
	{
		if (s1 == s2)
			return true;

		vector<int> count(26, 0);
		for (int i = 0; i < s1.length(); ++i)
		{
			count[s1[i] - 'a']++;
			count[s2[i] - 'a']--;
		}

		for (int i = 0; i < count.size(); ++i)
			if (count[i] != 0)
				return false;

		for (int i = 1; i < s1.length(); ++i)
		{
			bool flag_1 = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
						  isScramble(s1.substr(i), s2.substr(i));
			bool flag_2 = isScramble(s1.substr(0, i), s2.substr(s1.length() - i)) &&
						  isScramble(s1.substr(i), s2.substr(0, s1.length() - i));
			if (flag_1 || flag_2)
				return true;
		}
		return false;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
