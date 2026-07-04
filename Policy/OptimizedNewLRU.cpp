#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
    int cap;   
    std::list<int> cacheList; //list to store keys
    std::unordered_map<int, std::list<int>::iterator> cacheMap;

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) return -1;
        
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return *cacheMap[key];
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return;
        }

        if (cacheList.size() == cap) {
            int last = cacheList.back();
            cacheMap.erase(last);
            cacheList.pop_back();
        }

        cacheList.push_front(key);
        cacheMap[key] = cacheList.begin();
    }
};
