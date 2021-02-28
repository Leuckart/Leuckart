/**************************************************
	> File Name:  Leet_460_LFUCache.cpp
	> Author:     Leuckart
	> Time:       2020-04-05 13:51
**************************************************/

#include <unordered_map>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
class LFUCache
{
public:
	LFUCache(int capacity) : capacity(capacity) {}

	int get(int key)
	{
		if (keyValFreq.find(key) == keyValFreq.end())
			return -1;
		int freq = keyValFreq[key].second;
		freqKey[freq++].erase(keyIter[key]);
		freqKey[freq].emplace_front(key);
		keyIter[key] = freqKey[freq].begin();
		keyValFreq[key].second = freq;

		if (freqKey[minFreq].empty())
			minFreq = freq;

		return keyValFreq[key].first;
	}

	void put(int key, int value)
	{
		if (capacity <= 0)
			return;

		if (get(key) != -1)
		{
			keyValFreq[key].first = value;
			return;
		}

		if (keyValFreq.size() == capacity)
		{
			int delKey = freqKey[minFreq].back();
			freqKey[minFreq].pop_back();
			keyValFreq.erase(delKey);
			keyIter.erase(delKey);
		}

		minFreq = 1;
		keyValFreq[key] = make_pair(value, minFreq);
		freqKey[minFreq].emplace_front(key);
		keyIter[key] = freqKey[minFreq].begin();
	}

private:
	int capacity, minFreq;
	unordered_map<int, pair<int, int>> keyValFreq;
	unordered_map<int, list<int>> freqKey;
	unordered_map<int, list<int>::iterator> keyIter;
};

int main(int argc, char *argv[])
{
	LFUCache cache(2);

	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1);	 // returns 1
	cache.put(3, 3); // evicts key 2
	cache.get(2);	 // returns -1 (not found)
	cache.get(3);	 // returns 3.
	cache.put(4, 4); // evicts key 1.
	cache.get(1);	 // returns -1 (not found)
	cache.get(3);	 // returns 3
	cache.get(4);	 // returns 4

	return 0;
}
