/**************************************************
	> File Name:  Leet_187_RepeatedDNASequences.cpp
	> Author:     Leuckart
	> Time:       2020-09-18 00:42
**************************************************/

#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> findRepeatedDnaSequences(const string &s)
	{
		vector<string> result;
		unordered_map<int, int> Mp;

		int num = 0;
		for (int i = 0; i < 9 && i < s.length(); ++i)
			num = (num << 2) | DNA.find(s[i])->second;

		for (int i = 9; i < s.length(); ++i)
		{
			num = ((num << 2) | DNA.find(s[i])->second) & 0xFFFFF;

			unordered_map<int, int>::iterator iter = Mp.find(num);
			if (iter == Mp.end())
				Mp[num] = 1;
			else if (iter->second == 1)
			{
				result.push_back(s.substr(i - 9, 10));
				iter->second = 2;
			}
		}
		return result;
	}

private:
	const unordered_map<char, int> DNA{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
