/**************************************************
	> File Name:  Leet_017_LetterCombinations.cpp
	> Author:     Leuckart
	> Time:       2019-07-01 14:37
**************************************************/

#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> letterCombinations(const string digits)
	{
		if (digits.empty())
			return {};

		vector<string> ans;
		vector<string> pre = keyboard.find(digits[0])->second;
		vector<string> post = letterCombinations(digits.substr(1));

		if (post.empty())
		{
			for (int i = 0; i < pre.size(); ++i)
				ans.push_back(pre[i]);
		}
		else
		{
			for (int i = 0; i < pre.size(); ++i)
				for (int j = 0; j < post.size(); ++j)
					ans.push_back(pre[i] + post[j]);
		}
		return ans;
	}

private:
	const unordered_map<char, vector<string>> keyboard = {{'2', {"a", "b", "c"}},
														  {'3', {"d", "e", "f"}},
														  {'4', {"g", "h", "i"}},
														  {'5', {"j", "k", "l"}},
														  {'6', {"m", "n", "o"}},
														  {'7', {"p", "q", "r", "s"}},
														  {'8', {"t", "u", "v"}},
														  {'9', {"w", "x", "y", "z"}}};
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
