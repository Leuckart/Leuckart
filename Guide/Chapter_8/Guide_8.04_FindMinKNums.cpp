/**************************************************
	> File Name:  Guide_8.04_FindMinKNums.cpp
	> Author:     Leuckart
	> Time:       2020-10-13 18:28
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static vector<int> getMinKNums(const vector<int> &data, const int k)
	{
		if (k > data.size())
			return data;

		vector<int> heap(k, 0);
		for (int i = 0; i < k; ++i)
			heapInsert(heap, data[i], i);

		for (int i = k; i < data.size(); ++i)
		{
			if (data[i] < heap[0])
			{
				heap[0] = data[i];
				heapify(heap);
			}
		}
		return heap;
	}

private:
	static void heapInsert(vector<int> &heap, int val, int idx)
	{
		heap[idx] = val;
		while (idx != 0)
		{
			int parent = (idx - 1) / 2;
			if (heap[parent] >= heap[idx])
				break;
			swap(heap[parent], heap[idx]);
			idx = parent;
		}
	}

	static void heapify(vector<int> &heap)
	{
		int pos = 0;
		int lhs = pos * 2 + 1;
		int rhs = pos * 2 + 2;

		while (lhs < heap.size())
		{
			int largest = pos;
			if (heap[lhs] > heap[largest])
				largest = lhs;
			if (rhs < heap.size() && heap[rhs] > heap[largest])
				largest = rhs;

			if (largest == pos)
				break;
			swap(heap[pos], heap[largest]);
			pos = largest;
			lhs = pos * 2 + 1;
			rhs = pos * 2 + 2;
		}
	}
};

int main(int argc, char *argv[])
{
	Solution::getMinKNums({6, 9, 1, 3, 1, 2, 2, 5, 6, 1, 3, 5, 9, 7, 2, 5, 6, 1, 9}, 10);
	return 0;
}
