/**************************************************
	> File Name:  Leet_022_GenerateParentheses.cpp
	> Author:     Leuckart
	> Time:       2019-07-01 21:39
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> ans;
		generateParenthesisCore(ans, "", n, 0);
		return ans;
	}

private:
	void generateParenthesisCore(vector<string> &ans, string s, int lhs, int rhs)
	{
		if (lhs == 0 && rhs == 0)
			ans.push_back(s);
		if (lhs > 0)
			generateParenthesisCore(ans, s + "(", lhs - 1, rhs + 1);
		if (rhs > 0)
			generateParenthesisCore(ans, s + ")", lhs, rhs - 1);
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
