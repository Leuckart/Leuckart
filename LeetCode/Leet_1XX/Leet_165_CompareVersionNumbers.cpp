/**************************************************
	> File Name:  Leet_165_CompareVersionNumbers.cpp
	> Author:     Leuckart
	> Time:       2020-09-13 00:31
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int compareVersion(const string &version1, const string &version2)
	{
		vector<int> vec1 = string2vector(version1);
		vector<int> vec2 = string2vector(version2);

		for (int i = 0; i < vec1.size() && i < vec2.size(); ++i)
		{
			if (vec1[i] < vec2[i])
				return -1;
			else if (vec1[i] > vec2[i])
				return 1;
		}

		if (vec1.size() == vec2.size())
			return 0;
		return vec1.size() > vec2.size() ? 1 : -1;
	}

private:
	vector<int> string2vector(const string &str)
	{
		vector<int> result;
		for (int idx = 0; idx < str.length();)
		{
			int go = idx + 1;
			while (go < str.length() && str[go] != '.')
				++go;

			result.push_back(stoi(str.substr(idx, go - idx)));
			idx = go + 1;
		}
		while (result.size() > 1 && result.back() == 0)
			result.pop_back();
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
