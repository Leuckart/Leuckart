/**************************************************
	> File Name:  Sword_60_DicesProbability.cpp
	> Author:     Leuckart
	> Time:       2020-02-27 16:27
**************************************************/

// 面试题60：n个骰子的点数
// 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s
// 的所有可能的值出现的概率。

#include <iostream>
#include <vector>
using namespace std;

void PrintProbability(int number)
{
	if (number == 0)
		return;

	vector<long> Prob(number * 6 + 1, 0);
	for (int i = 1; i <= 6; ++i)
		Prob[i] = 1;

	for (int num = 2; num <= number; ++num)
	{
		int pre_low = (num - 1) * 1;
		int pre_high = (num - 1) * 6;

		for (int iter = pre_high; iter >= pre_low; --iter)
		{
			for (int plus = 6; plus >= 1; --plus)
				Prob[iter + plus] += Prob[iter];

			Prob[iter] = 0;
		}
	}

	int total = 0;
	for (int i = number; i <= number * 6; ++i)
		total += Prob[i];

	for (int i = number; i <= number * 6; ++i)
		cout << i << ":\t" << double(Prob[i]) / total << endl;
}

int main(int argc, char *argv[])
{
	PrintProbability(0);
	PrintProbability(1);
	PrintProbability(2);
	PrintProbability(3);
	PrintProbability(4);
	PrintProbability(11);

	return 0;
}
