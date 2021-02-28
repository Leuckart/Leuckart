/**************************************************
	> File Name:  demo4_sharedfuture1.cpp
	> Author:     Leuckart
	> Time:       2020-09-07 14:59
**************************************************/

#include <future>
#include <thread>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

int queryNumber()
{
	cout << "Read number: ";
	int num;
	cin >> num;

	if (!cin)
	{
		throw runtime_error("No number read.");
	}
	return num;
}

void doSomething(char c, shared_future<int> f)
{
	try
	{
		int num = f.get();
		for (int i = 0; i < num; ++i)
		{
			this_thread::sleep_for(chrono::milliseconds(100));
			cout.put(c).flush();
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "EXCEPTION in thread " << this_thread::get_id() << ": " << e.what() << std::endl;
	}
}

int main()
{
	try
	{
		shared_future<int> f = async(queryNumber);

		future<void> f1 = async(launch::async, doSomething, '.', f);
		future<void> f2 = async(launch::async, doSomething, '+', f);
		future<void> f3 = async(launch::async, doSomething, '*', f);

		f1.get();
		f2.get();
		f3.get();
	}
	catch (const std::exception &e)
	{
		std::cerr << "\nEXCEPTION: " << e.what() << std::endl;
	}
	cout << "\nDone" << std::endl;

	return 0;
}
