/**************************************************
	> File Name:  Leet_912_SortAnArray.cpp
	> Author:     Leuckart
	> Time:       2020-03-17 20:40
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sortArray(vector<int> &nums)
	{
		quickSort(nums, 0, nums.size() - 1);
		return nums;
	}

private:
	void quickSort(vector<int> &nums, int lhs, int rhs)
	{
		if (lhs >= rhs)
			return;

		int pivot = nums[rhs];

		int i = lhs;
		int j = rhs;
		while (i < j)
		{
			while (i < j && nums[i] <= pivot)
				++i;
			nums[j] = nums[i];

			while (i < j && nums[j] > pivot)
				--j;
			nums[i] = nums[j];
		}

		nums[i] = pivot;

		quickSort(nums, lhs, i - 1);
		quickSort(nums, i + 1, rhs);
	}

	void heapSort(vector<int> &nums)
	{
		for (int i = nums.size() / 2; i >= 0; --i)
			heapSortSiftDown(nums, nums.size(), i);

		for (int i = nums.size() - 1; i > 0; --i)
		{
			swap(nums[0], nums[i]);
			heapSortSiftDown(nums, i, 0);
		}
	}

	void heapSortSiftDown(vector<int> &nums, int n, int i)
	{
		int biggest = i;
		int lhs = 2 * i + 1;
		int rhs = 2 * i + 2;
		if (lhs < n && nums[biggest] < nums[lhs])
			biggest = lhs;
		if (rhs < n && nums[biggest] < nums[rhs])
			biggest = rhs;
		if (biggest != i)
		{
			swap(nums[i], nums[biggest]);
			heapSortSiftDown(nums, n, biggest);
		}
	}

	void mergeSort(vector<int> &nums, int lhs, int rhs)
	{
		if (lhs >= rhs)
			return;
		int mid = lhs + (rhs - lhs) / 2;
		mergeSort(nums, lhs, mid);
		mergeSort(nums, mid + 1, rhs);
		merge(nums, lhs, mid, rhs);
	}

	void merge(vector<int> &nums, int lhs, int mid, int rhs)
	{
		vector<int> tmp(rhs - lhs + 1);
		int i = lhs;	 // index for left subarray
		int j = mid + 1; // index for right subarray
		int k = 0;		 // index for temporary array
		while (i <= mid && j <= rhs)
		{
			if (nums[i] <= nums[j])
			{
				tmp[k] = nums[i];
				i++;
			}
			else
			{
				tmp[k] = nums[j];
				j++;
			}
			k++;
		}
		while (i <= mid)
		{
			tmp[k] = nums[i];
			i++;
			k++;
		}
		while (j <= rhs)
		{
			tmp[k] = nums[j];
			j++;
			k++;
		}
		for (i = 0; i < k; i++)
			nums[lhs + i] = tmp[i];
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
