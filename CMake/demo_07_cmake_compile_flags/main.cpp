/**************************************************
	> File Name:  main.cpp
	> Author:     Leuckart
	> Time:       2020-06-20 12:12
**************************************************/

#include <iostream>

int main(int argc, char *argv[])
{
  std::cout << "Hello Compile Flags. By Leuckart." << std::endl;

#ifdef EX2
  std::cout << "Hello Compile Flag EX2. By Leuckart." << std::endl;
#endif

#ifdef EX3
  std::cout << "Hello Compile Flag EX3. By Leuckart." << std::endl;
#endif

  return 0;
}
