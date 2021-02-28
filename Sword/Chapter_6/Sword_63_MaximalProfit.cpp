/**************************************************
	> File Name:  Sword_63_MaximalProfit.cpp
	> Author:     Leuckart
	> Time:       2020-02-28 02:10
**************************************************/

// 面试题63：股票的最大利润
// 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股
// 票可能获得的利润是多少？例如一只股票在某些时间节点的价格为{9, 11, 8, 5,
// 7, 12, 16, 14}。如果我们能在价格为5的时候买入并在价格为16时卖出，则能
// 收获最大的利润11。

#include <cassert>
#include <vector>
using namespace std;

int MaxProfit(const vector<int> nums)
{
	if (nums.size() < 2)
		return 0;

	int min_pos = 0;
	int max_profit = nums[1] - nums[0];

	for (size_t i = 1; i < nums.size(); ++i)
	{
		if (nums[i] - nums[min_pos] > max_profit)
			max_profit = nums[i] - nums[min_pos];
		if (nums[i] <= nums[min_pos])
			min_pos = i;
	}
	return max_profit;
}

int main(int argc, char *argv[])
{
	assert(MaxProfit({4, 1, 3, 2, 5}) == 4);
	assert(MaxProfit({1, 2, 4, 7, 11, 16}) == 15);
	assert(MaxProfit({16, 16, 16, 16, 16}) == 0);
	assert(MaxProfit({9, 11, 5, 7, 16, 1, 4, 2}) == 11);
	assert(MaxProfit({16, 11, 7, 4, 2, 1}) == -1);
	assert(MaxProfit({2, 4}) == 2);
	assert(MaxProfit({4, 2}) == -2);

	return 0;
}
