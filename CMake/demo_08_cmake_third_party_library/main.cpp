/**************************************************
	> File Name:  main.cpp
	> Author:     Leuckart
	> Time:       2020-06-21 00:27
**************************************************/

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>

int main(int argc, char *argv[])
{
    std::cout << "Hello Third Party Library. By Leuckart." << std::endl;

    // use a shared ptr
    boost::shared_ptr<int> isp(new int(4));

    // trivial use of boost filesystem
    boost::filesystem::path path = "/usr/share/cmake/modules";
    if(path.is_relative())
    {
        std::cout << "Path is relative. By Leuckart." << std::endl;
    }
    else
    {
        std::cout << "Path is not relative. By Leuckart." << std::endl;
    }

   return 0;
}
