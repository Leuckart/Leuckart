/**************************************************
	> File Name:  demo2_async2.cpp
	> Author:     Leuckart
	> Time:       2020-09-05 23:29
**************************************************/

#include <future>
#include <list>
#include <iostream>
#include <exception>
using namespace std;

void task1()
{
	list<int> v;
	while (true)
	{
		for (int i = 0; i < 1000000; ++i)
			v.push_back(i);
		cout.put('.').flush();
	}
}

int main()
{
	std::cout << "Starting 2 tasks" << std::endl;
	std::cout << "- Task1: process endless loop of memory consumption" << std::endl;
	std::cout << "- Task2: wait for <return> and then for task1" << std::endl;

	std::future<void> f1 = async(task1);
	cin.get();

	std::cout << "\nWait for the end of task1: " << std::endl;
	try
	{
		f1.get();
	}
	catch (const std::exception &e)
	{
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}

	return 0;
}
