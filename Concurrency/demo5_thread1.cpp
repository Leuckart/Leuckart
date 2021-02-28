/**************************************************
	> File Name:  demo5_thread1.cpp
	> Author:     Leuckart
	> Time:       2020-09-07 15:52
**************************************************/

#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;

void doSomething(int num, char c)
{
	try
	{
		default_random_engine dre(42 * c);
		uniform_int_distribution<int> id(10, 1000);
		for (int i = 0; i < num; ++i)
		{
			this_thread::sleep_for(chrono::milliseconds(id(dre)));
			cout.put(c).flush();
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "THREAD-EXCEPTION (thread " << this_thread::get_id() << "): " << e.what() << std::endl;
	}
}

int main()
{
	try
	{
		thread t1(doSomething, 5, '.');
		std::cout << "- Started fd thread " << t1.get_id() << std::endl;

		for (int i = 0; i < 5; ++i)
		{
			thread t(doSomething, 10, 'a' + i);
			cout << "- Detach started bg thread " << t.get_id() << std::endl;
			t.detach();
		}
		cin.get();
		cout << "- Join fg thread " << t1.get_id() << std::endl;
		t1.join();
	}
	catch (const std::exception &e)
	{
		std::cerr << "\nEXCEPTION: " << e.what() << std::endl;
	}

	return 0;
}
