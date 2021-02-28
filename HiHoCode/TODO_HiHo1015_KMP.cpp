/**************************************************
	> File Name:  HiHo1015_KMP.cpp
	> Author:     Leuckart
	> Time:       2017-07-20 22:23
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getNextTables(const string &str)
{
	int len = str.length();
	vector<int> Next(len, 0);
	Next[0] = -1;

	for (int i = 0, j = -1; i < len;)
	{
		if (j == -1 || str[i] == str[j])
		{
			i++;
			j++;
			Next[i] = j;
		}
		else
			j = Next[j];
	}
	return Next;
}

int main()
{
	int N;
	cin >> N;

	while (N-- > 0)
	{
		string Patt, Strs;
		cin >> Patt >> Strs;

		int lenP = Patt.length();
		int lenS = Strs.length();

		vector<int> kmpNext = getNextTables(Strs);

		int occur = 0;
		for (int pi = 0, si = 0; pi < lenP && si < lenS;)
		{
			if (pi == -1 || Patt[pi] == Strs[si])
			{
				pi++;
				si++;
			}
			else
				pi = kmpNext[pi];

			if (pi == lenP)
			{
				pi = kmpNext[lenP - 1];
				si--;
				occur++;
			}
		}
		cout << occur << endl;
	}
	return 0;
}
