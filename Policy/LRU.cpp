#include <iostream>
#include <unordered_map>
#include <list>

class Cache {
    int cap;
    std::list<int> l;
    std::unordered_map<int, std::list<int>::iterator> m;

public:
    Cache(int c) : cap(c) {}

    void get(int k) {
        if (m.find(k) == m.end()) return;
        l.erase(m[k]);
        l.push_front(k);
        m[k] = l.begin();
    }

    void put(int k) {
        if (m.find(k) != m.end()) {
            l.erase(m[k]);
        } else if (l.size() == cap) {
            m.erase(l.back());
            l.pop_back();
        }
        l.push_front(k);
        m[k] = l.begin();
    }
};

int main() {
    Cache c(2);
    c.put(1);
    c.put(2);
    c.get(1);
    c.put(3);
    return 0;
}


// Least receently used , it evicts process thst is the least acessed at the end of cycle ,
// I will try to change naming and optimize the code