/**************************************************
	> File Name:  Guide_1.05_HanoiStack.cpp
	> Author:     Leuckart
	> Time:       2020-10-02 17:59
**************************************************/

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

const string Tower_Lhs = "左";
const string Tower_Mid = "中";
const string Tower_Rhs = "右";

class Solution
{
public:
	static int solveHanoi(const int num)
	{
		if (num < 1)
			return 0;
		return process(num, Tower_Lhs, Tower_Rhs);
	}

private:
	static int process(const int num, const string &src, const string &dst)
	{
		if (num == 1)
		{
			if (src == Tower_Mid || dst == Tower_Mid)
			{
				cout << "Move 1 from " + src + " to " + dst << endl;
				return 1;
			}
			else
			{
				cout << "Move 1 from " + src + " to " << Tower_Mid << endl;
				cout << "Move 1 from " + Tower_Mid + " to " + dst << endl;
				return 2;
			}
		}

		if (src == Tower_Mid || dst == Tower_Mid)
		{
			string other = (src == Tower_Lhs || dst == Tower_Lhs) ? Tower_Rhs : Tower_Lhs;
			int part1 = process(num - 1, src, other);
			int part2 = 1;
			cout << "Move " << num << " from " << src << " to " << dst << endl;
			int part3 = process(num - 1, other, dst);
			return part1 + part2 + part3;
		}
		else
		{
			int part1 = process(num - 1, src, dst);
			int part2 = 1;
			cout << "Move " << num << " from " << src << " to " << Tower_Mid << endl;
			int part3 = process(num - 1, dst, src);
			int part4 = 1;
			cout << "Move " << num << " from " << Tower_Mid << " to " << dst << endl;
			int part5 = process(num - 1, src, dst);
			return part1 + part2 + part3 + part4 + part5;
		}
	}
};

int main(int argc, char *argv[])
{
	assert(Solution::solveHanoi(4) == 80);
	return 0;
}
