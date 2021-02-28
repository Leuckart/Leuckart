/**************************************************
	> File Name:  Leet_146_LRUCache.cpp
	> Author:     Leuckart
	> Time:       2020-03-15 03:48
**************************************************/

#include <unordered_map>
#include <iostream>
#include <list>
using namespace std;

class LRUCache
{
public:
	LRUCache(int capacity) : my_capacity(capacity) {}

	int get(int key)
	{
		unordered_map<int, pair<int, list<int>::iterator>>::iterator iter = my_map.find(key);
		if (iter == my_map.end())
			return -1;

		my_list.erase(iter->second.second);
		my_list.push_front(key);
		iter->second.second = my_list.begin();
		return iter->second.first;
	}

	void put(int key, int value)
	{
		unordered_map<int, pair<int, list<int>::iterator>>::iterator iter = my_map.find(key);
		if (iter == my_map.end())
		{
			if (my_map.size() == my_capacity)
			{
				my_map.erase(my_list.back());
				my_list.pop_back();
			}
			my_list.push_front(key);
		}
		else
		{
			my_list.erase(iter->second.second);
			my_list.push_front(key);
			iter->second.second = my_list.begin();
		}
		my_map[key] = pair<int, list<int>::iterator>(value, my_list.begin());
	}

private:
	int my_capacity;
	unordered_map<int, pair<int, list<int>::iterator>> my_map;
	list<int> my_list;
};

int main(int argc, char *argv[])
{
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl; // returns 1
	cache.put(3, 3);
	cout << cache.get(2) << endl; // returns -1
	cache.put(4, 4);
	cout << cache.get(1) << endl; // returns -1
	cout << cache.get(3) << endl; // returns 3
	cout << cache.get(4) << endl; // returns 4

	return 0;
}
