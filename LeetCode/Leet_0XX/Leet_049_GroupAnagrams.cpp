/**************************************************
	> File Name:  Leet_049_GroupAnagrams.cpp
	> Author:     Leuckart
	> Time:       2019-07-15 20:22
**************************************************/

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<vector<string>> groupAnagrams(const vector<string> &strs)
	{
		vector<vector<string>> result;
		unordered_map<string, vector<string>> dict;

		for (int i = 0; i < strs.size(); ++i)
		{
			string key = strs[i];
			sort(key.begin(), key.end());
			dict[key].push_back(strs[i]);
		}

		for (unordered_map<string, vector<string>>::const_iterator iter = dict.cbegin(); iter != dict.cend(); ++iter)
			result.push_back(iter->second);
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
