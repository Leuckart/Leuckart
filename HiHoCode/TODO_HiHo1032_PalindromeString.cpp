/**************************************************
	> File Name:  HiHo1032_PalindromeString.cpp
	> Author:     Leuckart
	> Time:       2017-07-22 15:44
**************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int numberOfAns;
	cin >> numberOfAns;
	int noa = 0;
	string si;

	while (noa < numberOfAns && cin >> si)
	{
		int lenSi = si.length();
		int lenS = 2 * lenSi + 2;
		string s(lenS, '#');
		s[0] = '$';
		for (int i = 0; i < lenSi; i++)
		{
			s[2 * i + 2] = si[i];
		}

		vector<int> Flen(2 * lenS + 2, 0);//Maybe lenSi

		int j = 1;
		Flen[0] = Flen[1] = 1;
		int maxRange = 1;
		int maxLong = 1;
		int k;

		for (int i = 2; i < lenS; i++)
		{
			if (i > maxRange)
			{
				Flen[i] = 1;
			}
			else
			{
				Flen[i] = min(Flen[2 * j - i], maxRange - i);
			}
			while (s[i - Flen[i]] == s[i + Flen[i]])
				Flen[i]++;
			if (maxRange < i + Flen[i])
			{
				j = i;
				maxRange = i + Flen[i];
			}

			maxLong = max(maxLong, Flen[i] - 1);
		}
		cout << maxLong << endl;
		noa++;
	}
	return 0;
}
