/**************************************************
	> File Name:  Leet_164_MaximumGap.cpp
	> Author:     Leuckart
	> Time:       2020-09-12 02:36
**************************************************/

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <tuple>
using namespace std;

class Solution
{
public:
	int maximumGap(const vector<int> &nums)
	{
		if (nums.size() < 2)
			return 0;

		int max_val = *max_element(nums.cbegin(), nums.cend());
		int min_val = *min_element(nums.cbegin(), nums.cend());

		int bucket_size = max(1, (max_val - min_val) / (static_cast<int>(nums.size()) - 1));
		int bucket_num = (max_val - min_val) / bucket_size + 1;
		vector<tuple<bool, int, int>> buckets(bucket_num, make_tuple(false, INT_MAX, INT_MIN));

		for (int i = 0; i < nums.size(); ++i)
		{
			int idx = (nums[i] - min_val) / bucket_size;
			std::get<0>(buckets[idx]) = true;
			std::get<1>(buckets[idx]) = min(std::get<1>(buckets[idx]), nums[i]);
			std::get<2>(buckets[idx]) = max(std::get<2>(buckets[idx]), nums[i]);
		}

		int result = 0;
		int prev_max = min_val;
		for (int i = 0; i < buckets.size(); ++i)
		{
			if (!std::get<0>(buckets[i]))
				continue;

			result = max(result, std::get<1>(buckets[i]) - prev_max);
			prev_max = std::get<2>(buckets[i]);
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
