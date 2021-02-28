/**************************************************
	> File Name:  demo3_async3.cpp
	> Author:     Leuckart
	> Time:       2020-09-06 23:34
**************************************************/

#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;

int doSomething(char c)
{
	std::default_random_engine dre(c);
	std::uniform_int_distribution<int> id(10, 1000);

	for (int i = 0; i < 10; ++i)
	{
		this_thread::sleep_for(chrono::milliseconds(id(dre)));
		cout.put(c).flush();
	}
	return c;
}

int main()
{
	std::cout << "Starting 2 operations asynchoronously" << std::endl;

	std::future<int> f1 = async([] { return doSomething('.'); });
	std::future<int> f2 = async([] { return doSomething('+'); });

	if (f1.wait_for(chrono::seconds(0)) != future_status::deferred ||
		f2.wait_for(chrono::seconds(0)) != future_status::deferred)
	{
		while (f1.wait_for(chrono::seconds(0)) != future_status::ready ||
			   f2.wait_for(chrono::seconds(0)) != future_status::ready)
		{
			;
			this_thread::yield();
		}
	};

	cout.put('\n').flush();

	try
	{
		f1.get();
		f2.get();
	}
	catch (const std::exception &e)
	{
		std::cerr << "\nEXCEPTION: " << e.what() << std::endl;
	}
	std::cout << "\nDone" << std::endl;

	return 0;
}
