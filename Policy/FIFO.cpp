#include <iostream>
#include <queue>
#include <unordered_set>

class Cache {
    int cap;
    std::queue<int> q;
    std::unordered_set<int> s;

public:
    Cache(int c) : cap(c) {}

    void get(int k) {
        if (s.find(k) == s.end()) return;
    }

    void put(int k) {
        if (s.find(k) != s.end()) return;
        if (s.size() == cap) {
            s.erase(q.front());
            q.pop();
        }
        q.push(k);
        s.insert(k);
    }
};


int main() {
    Cache c(2);
    c.put(1);
    c.put(2);
    c.put(3);
    return 0;
}

// This implementation logic same as Queue i.e FIFO
