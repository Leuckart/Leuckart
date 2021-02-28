/**************************************************
	> File Name:  Sword_12_StringPathInMatrix.cpp
	> Author:     Leuckart
	> Time:       2020-02-16 23:30
**************************************************/

// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
using namespace std;

bool hasPathRecursive(const vector<string> &mat, vector<vector<bool>> &visited,
					  const string str, const int row, const int col)
{
	if (str.empty())
		return true;
	if (row >= mat.size() || col >= mat[0].size())
		return false;

	if (mat[row][col] == str[0] && !visited[row][col])
	{
		visited[row][col] = true;
		if (hasPathRecursive(mat, visited, str.substr(1), row, col + 1) ||
			hasPathRecursive(mat, visited, str.substr(1), row + 1, col) ||
			hasPathRecursive(mat, visited, str.substr(1), row, col - 1) ||
			hasPathRecursive(mat, visited, str.substr(1), row - 1, col))
			return true;
		visited[row][col] = false;
	}
	else
	{
		return false;
	}
	return false;
}

bool hasPath(const vector<string> &mat, const string str)
{
	if (str.empty() || mat.empty() || mat[0].empty())
		return false;

	int row = mat.size();
	int col = mat[0].size();
	vector<vector<bool>> visited(row, vector<bool>(col, false));

	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < col; ++j)
		{
			if (hasPathRecursive(mat, visited, str, i, j))
			{
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char *argv[])
{
	assert(hasPath({"ABTG", "CFCS", "JDEH"}, "BFCE"));
	assert(hasPath({"ABCE", "SFCS", "ADEE"}, "SEE"));
	assert(!hasPath({"ABTG", "CFCS", "JDEH"}, "ABFB"));

	assert(hasPath({"ABCEHJIG", "SFCSLOPQ", "ADEEMNOE", "ADIDEJFM", "VCEIFGGS"}, "SLHECCEIDEJFGGFIE"));
	assert(hasPath({"ABCEHJIG", "SFCSLOPQ", "ADEEMNOE", "ADIDEJFM", "VCEIFGGS"}, "SGGFIECVAASABCEHJIGQEM"));
	assert(!hasPath({"ABCEHJIG", "SFCSLOPQ", "ADEEMNOE", "ADIDEJFM", "VCEIFGGS"}, "SGGFIECVAASABCEEJIGOEM"));
	assert(!hasPath({"ABCEHJIG", "SFCSLOPQ", "ADEEMNOE", "ADIDEJFM", "VCEIFGGS"}, "SGGFIECVAASABCEHJIGQEMS"));

	assert(hasPath({"AAAA", "AAAA", "AAAA"}, "AAAAAAAAAAAA"));
	assert(!hasPath({"AAAA", "AAAA", "AAAA"}, "AAAAAAAAAAAAA"));
	assert(hasPath({"A"}, "A"));
	assert(!hasPath({"A"}, "B"));
	assert(!hasPath({""}, ""));

	return 0;
}
