/**************************************************
	> File Name:  Leet_077_Combinations.cpp
	> Author:     Leuckart
	> Time:       2019-07-23 17:32
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> result;
		vector<int> item;
		combineCore(result, item, n, k);
		return result;
	}

private:
	void combineCore(vector<vector<int>> &result, vector<int> &item, int n, int k)
	{
		if (k == 0)
		{
			result.push_back(item);
			return;
		}

		for (int i = n; i >= k; --i)
		{
			item.push_back(i);
			combineCore(result, item, i - 1, k - 1);
			item.pop_back();
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
