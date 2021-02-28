/**************************************************
	> File Name:  Leet_1111_MaximumNestingDepth.cpp
	> Author:     Leuckart
	> Time:       2020-04-01 15:33
**************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> maxDepthAfterSplit(const string &seq)
	{
		int cur_depth = 0;
		vector<int> depth(seq.length(), 0);
		for (int i = 0; i < seq.length(); ++i)
		{
			if (seq[i] == '(')
			{
				depth[i] = cur_depth;
				cur_depth++;
			}
			else
			{
				cur_depth--;
				depth[i] = cur_depth;
			}
		}
		for (int i = 0; i < depth.size(); ++i)
			depth[i] %= 2;
		return depth;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
