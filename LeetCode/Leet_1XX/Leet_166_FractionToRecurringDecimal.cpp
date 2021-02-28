/**************************************************
	> File Name:  Leet_166_FractionToRecurringDecimal.cpp
	> Author:     Leuckart
	> Time:       2020-09-13 00:48
**************************************************/

#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string fractionToDecimal(const int numerator, const int denominator)
	{
		bool flag = (numerator >= 0 && denominator >= 0) ||
					(numerator <= 0 && denominator <= 0);

		long num = abs(static_cast<long>(numerator));
		long denom = abs(static_cast<long>(denominator));
		if (num % denom == 0)
			return (flag ? string() : string("-")) + string() + to_string(num / denom);

		string lhs = (flag ? string() : string("-")) + to_string(num / denom) + ".";
		string rhs;

		unordered_map<int, int> Mp;
		long remainder = num % denom;

		while (remainder && Mp.find(remainder) == Mp.cend())
		{
			Mp[remainder] = rhs.length();
			num = remainder * 10;

			rhs += to_string(num / denom);
			remainder = num % denom;
		}
		if (remainder)
			return lhs + rhs.substr(0, Mp[remainder]) + "(" + rhs.substr(Mp[remainder]) + ")";
		else
			return lhs + rhs;
	}
};

int main(int argc, char *argv[])
{
	Solution sol;
	return 0;
}
