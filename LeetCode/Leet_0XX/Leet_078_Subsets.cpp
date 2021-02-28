/**************************************************
	> File Name:  Leet_078_Subsets.cpp
	> Author:     Leuckart
	> Time:       2019-07-23 18:13
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> subsets(const vector<int> &nums)
	{
		vector<vector<int>> result;
		vector<int> item;
		subsetsCore(result, item, nums, 0);
		return result;
	}

private:
	void subsetsCore(vector<vector<int>> &result, vector<int> &item, const vector<int> &nums, int index)
	{
		result.push_back(item);
		for (int i = index; i < nums.size(); ++i)
		{
			item.push_back(nums[i]);
			subsetsCore(result, item, nums, i + 1);
			item.pop_back();
		}
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
