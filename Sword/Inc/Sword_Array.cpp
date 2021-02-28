/**************************************************
	> File Name:  Sword_Array.cpp
	> Author:     Leuckart
	> Time:       2020-02-19 16:16
**************************************************/

#include <exception>
#include "./Sword_Array.h"

int Partition(std::vector<int> vec, int beg, int end)
{
	if (vec.empty() || beg < 0 || end > vec.size() || beg > end)
		throw new std::exception();

	int pivot = beg;
	while (pivot < end && vec[pivot] <= vec[end])
	{
		++pivot;
	}

	int tmp = vec[pivot];
	vec[pivot] = vec[end];
	vec[end] = tmp;

	return pivot;
}
