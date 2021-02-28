/**************************************************
	> File Name:  Leet_071_SimplifyPath.cpp
	> Author:     Leuckart
	> Time:       2019-07-22 13:59
**************************************************/

#include <iostream>
#include <string>
#include <deque>
using namespace std;

class Solution
{
public:
	string simplifyPath(const string path)
	{
		deque<string> D;
		int index = 0;
		while (index < path.size())
		{
			while (index < path.length() && path[index] == '/')
				++index;
			if (index == path.size())
				break;

			// 寻找下一个 '/'
			int new_index = index + 1;
			while (new_index < path.length() && path[new_index] != '/')
				++new_index;

			string tmp = path.substr(index, new_index - index);
			if (tmp == "..")
			{
				if (!D.empty())
					D.pop_back();
			}
			else if (tmp != ".")
				D.push_back(tmp);

			index = new_index + 1;
		}

		if (D.empty())
			return "/";

		string result;
		while (!D.empty())
		{
			result += "/" + D.front();
			D.pop_front();
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
