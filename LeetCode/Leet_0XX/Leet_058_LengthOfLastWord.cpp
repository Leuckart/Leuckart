/**************************************************
	> File Name:  Leet_058_LengthOfLastWord.cpp
	> Author:     Leuckart
	> Time:       2019-07-07 12:21
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int lengthOfLastWord(const string s)
	{
		int pos_2 = s.size() - 1;
		while (pos_2 >= 0 && s[pos_2] == ' ')
			--pos_2;

		int pos_1 = pos_2;
		while (pos_1 >= 0 && s[pos_1] != ' ')
			--pos_1;

		return pos_2 - pos_1;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
