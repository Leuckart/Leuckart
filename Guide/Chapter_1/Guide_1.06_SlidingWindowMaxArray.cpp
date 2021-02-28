/**************************************************
	> File Name:  Guide_1.06_SlidingWindowMaxArray.cpp
	> Author:     Leuckart
	> Time:       2020-10-03 22:37
**************************************************/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
	static vector<int> getMaxWindow(const vector<int> &data, const int w)
	{
		if (w < 1 || data.size() < w)
			return {};

		vector<int> result;
		deque<int> qmax;
		for (int i = 0; i < data.size(); ++i)
		{
			while (!qmax.empty() && data[qmax.back()] < data[i])
				qmax.pop_back();
			qmax.push_back(i);

			if (qmax.front() < i - w + 1)
				qmax.pop_front();

			if (i >= w - 1)
				result.push_back(data[qmax.front()]);
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	const vector<int> data{4, 3, 5, 4, 3, 3, 6, 7};
	const vector<int> result = Solution::getMaxWindow(data, 3);

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}
