/**************************************************
	> File Name:  main.cpp
	> Author:     Leuckart
	> Time:       2019-12-23 09:41
**************************************************/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string str("Hello World ");
	str.append(std::to_string(1996) + ".\n");

	for (std::string::const_iterator it = str.cbegin(); it != str.cend();)
		std::cout << *it++;
	return 0;
}
