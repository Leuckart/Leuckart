/**************************************************
	> File Name:  Leet_179_LargestNumber.cpp
	> Author:     Leuckart
	> Time:       2020-09-14 01:27
**************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution
{
public:
	string largestNumber(const vector<int> &nums)
	{
		priority_queue<string, vector<string>, cmp> Pq;
		for (int i = 0; i < nums.size(); ++i)
			Pq.emplace(to_string(nums[i]));

		if (!Pq.empty() && Pq.top() == "0")
			return "0";

		string result;
		while (!Pq.empty())
		{
			result += Pq.top();
			Pq.pop();
		}
		return result;
	}

private:
	struct cmp
	{
		bool operator()(const string &a, const string &b)
		{
			const string ab(a + b);
			const string ba(b + a);
			for (int i = 0; i < ab.length() + ba.length(); ++i)
			{
				if (ab[i] < ba[i])
					return true;
				if (ab[i] > ba[i])
					return false;
			}
			return true;
		}
	};
};

int main(int argc, char *argv[])
{
	Solution sol;
	//cout << sol.cmp(10, 2) << endl;
	vector<int> vec{3, 30, 34, 5, 9};
	cout << sol.largestNumber(vec) << endl;
	return 0;
}
