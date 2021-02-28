/**************************************************
	> File Name:  Sword_13_RobotMove.cpp
	> Author:     Leuckart
	> Time:       2020-02-17 00:54
**************************************************/

// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int getDigitSum(int num)
{
	int ans = 0;
	while (num > 0)
	{
		ans += num % 10;
		num /= 10;
	}
	return ans;
}

int movingCountRecursive(vector<vector<bool>> &visited, int row, int col, int ths)
{
	if (row < 0 || row >= visited.size() ||
		col < 0 || col >= visited[0].size() ||
		visited[row][col] == true ||
		getDigitSum(row) + getDigitSum(col) > ths)
		return 0;

	visited[row][col] = true;
	return 1 + movingCountRecursive(visited, row + 1, col, ths) +
		   movingCountRecursive(visited, row, col + 1, ths) +
		   movingCountRecursive(visited, row - 1, col, ths) +
		   movingCountRecursive(visited, row, col - 1, ths);
}

int movingCount(int row, int col, int ths)
{
	if (row < 1 || col < 1 || ths < 0)
		return 0;

	vector<vector<bool>> visited(row, vector<bool>(col, false));
	return movingCountRecursive(visited, 0, 0, ths);
}

int main(int agrc, char *argv[])
{
	assert(movingCount(10, 10, 5) == 21);
	assert(movingCount(20, 20, 15) == 359);
	assert(movingCount(1, 100, 10) == 29);
	assert(movingCount(1, 10, 10) == 10);
	assert(movingCount(100, 1, 15) == 79);
	assert(movingCount(10, 1, 15) == 10);
	assert(movingCount(1, 1, 15) == 1);
	assert(movingCount(1, 1, 0) == 1);
	assert(movingCount(10, 10, -10) == 0);

	return 0;
}
