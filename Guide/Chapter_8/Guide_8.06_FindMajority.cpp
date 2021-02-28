/**************************************************
	> File Name:  Guide_8.06_FindMajority.cpp
	> Author:     Leuckart
	> Time:       2020-10-12 09:34
**************************************************/

#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static vector<int> kMajor(const vector<int> &data, const int k)
	{
		// 以K个不同元素为一组，进行筛选
		unordered_map<int, int> Mp;
		for (int i = 0; i < data.size(); ++i)
		{
			if (Mp.find(data[i]) != Mp.end())
				++Mp[data[i]];
			else
			{
				if (Mp.size() == k - 1)
				{
					unordered_set<int> remove_set;
					for (unordered_map<int, int>::iterator iter = Mp.begin(); iter != Mp.end(); ++iter)
					{
						if (iter->second == 1)
							remove_set.insert(iter->first);
						iter->second = iter->second - 1;
					}
					for (unordered_set<int>::const_iterator iter = remove_set.cbegin(); iter != remove_set.cend(); ++iter)
						Mp.erase(*iter);
				}
				else
					Mp[data[i]] = 1;
			}
		}

		// 获得Mp中元素的真实出现次数
		unordered_map<int, int> counts;
		for (int i = 0; i < data.size(); ++i)
		{
			if (Mp.count(data[i]))
			{
				if (counts.count(data[i]))
					++counts[data[i]];
				else
					counts[data[i]] = 1;
			}
		}

		vector<int> result;
		for (unordered_map<int, int>::const_iterator iter = counts.cbegin(); iter != counts.cend(); ++iter)
			if (iter->second > data.size() / k)
				result.push_back(iter->first);
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution::kMajor({1, 2, 3, 1, 1, 2, 1}, 4);
	Solution::kMajor({1, 2, 3, 1, 2, 3, 4}, 7);
	Solution::kMajor({1, 1, 2, 3}, 1);
	return 0;
}
