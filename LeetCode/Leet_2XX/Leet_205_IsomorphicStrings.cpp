/**************************************************
	> File Name:  Leet_205_IsomorphicStrings.cpp
	> Author:     Leuckart
	> Time:       2020-09-18 17:02
**************************************************/

#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
	bool isIsomorphic(const string &s, const string &t)
	{
		unordered_map<char, char> s2t;
		unordered_map<char, char> t2s;

		for (int i = 0; i < s.length(); ++i)
		{
			unordered_map<char, char>::const_iterator iter_s2t = s2t.find(s[i]);
			unordered_map<char, char>::const_iterator iter_t2s = t2s.find(t[i]);

			if (iter_s2t == s2t.cend() &&
				(iter_t2s == t2s.cend() ||
				 (iter_t2s != t2s.cend() && iter_t2s->second == s[i])))
			{
				s2t[s[i]] = t[i];
				t2s[t[i]] = s[i];
			}
			else if ((iter_s2t != s2t.cend() && iter_s2t->second != t[i]) ||
					 (iter_t2s != t2s.cend() && iter_t2s->second != s[i]))
				return false;
		}
		return true;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
