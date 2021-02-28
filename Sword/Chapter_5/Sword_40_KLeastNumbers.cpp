/**************************************************
	> File Name:  Sword_40_KLeastNumbers.cpp
	> Author:     Leuckart
	> Time:       2020-02-25 15:05
**************************************************/

// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int Partion(vector<int> &input, int low, int high)
{
	int pivot = input[low];
	while (low < high)
	{
		while (low < high && input[high] > pivot)
			--high;
		input[low] = input[high];

		while (low < high && input[low] <= pivot)
			++low;
		input[high] = input[low];
	};
	input[low] = pivot;
	return low;
}

vector<int> GetLeastNumbers_Solution1(vector<int> &input, int k)
{
	if (input.empty() || k <= 0 || k > input.size())
		return {};

	int beg = 0;
	int end = input.size() - 1;
	int index = Partion(input, beg, end);
	while (index != k - 1)
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = Partion(input, beg, end);
		}
		else
		{
			beg = index + 1;
			index = Partion(input, beg, end);
		}
	}

	vector<int> Ans;
	for (size_t i = 0; i < k; ++i)
		Ans.push_back(input[i]);
	return Ans;
}

// ====================方法2====================
vector<int> GetLeastNumbers_Solution2(const vector<int> &input, int k)
{
	if (input.empty() || k <= 0 || k > input.size())
		return {};

	multiset<int, std::greater<int>> leastNumbers;
	for (vector<int>::const_iterator iter = input.cbegin(); iter != input.cend(); ++iter)
	{
		if (leastNumbers.size() < k)
			leastNumbers.insert(*iter);
		else
		{
			multiset<int, std::greater<int>>::iterator iterGreatest = leastNumbers.begin();
			if (*iter < *iterGreatest)
			{
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}

	vector<int> Ans;
	for (multiset<int, std::greater<int>>::const_iterator iter = leastNumbers.cbegin(); iter != leastNumbers.cend(); ++iter)
		Ans.push_back(*iter);
	return Ans;
}

void Print(vector<int> vec)
{
	for (auto i : vec)
		cout << i << "\t";
	cout << endl;
}

int main(int argc, char *argv[])
{
	vector<int> input1 = {4, 5, 1, 6, 2, 7, 3, 8};
	Print(GetLeastNumbers_Solution1(input1, 4));
	Print(GetLeastNumbers_Solution2(input1, 4));

	vector<int> input2 = {4, 5, 1, 6, 2, 7, 3, 8};
	Print(GetLeastNumbers_Solution1(input2, 8));
	Print(GetLeastNumbers_Solution2(input2, 8));

	vector<int> input3 = {4, 5, 1, 6, 2, 7, 3, 8};
	Print(GetLeastNumbers_Solution1(input3, 10));
	Print(GetLeastNumbers_Solution2(input3, 10));

	vector<int> input4 = {4, 5, 1, 6, 2, 7, 3, 8};
	Print(GetLeastNumbers_Solution1(input4, 1));
	Print(GetLeastNumbers_Solution2(input4, 1));

	vector<int> input5 = {4, 5, 1, 6, 2, 7, 2, 8};
	Print(GetLeastNumbers_Solution1(input5, 3));
	Print(GetLeastNumbers_Solution2(input5, 3));

	return 0;
}
