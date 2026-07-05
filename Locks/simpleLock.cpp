#include <iostream>
#include <mutex>
#include <thread>

int shared_balance = 0;
std::mutex mtx; 


void update_balance() {
    for (int i = 0; i < 10000; ++i) {
        std::lock_guard<std::mutex> guard(mtx);
        shared_balance = shared_balance + 1;
    }
}


int main() {
    std::thread t1(update_balance);
    std::thread t2(update_balance);

    t1.join();
    t2.join();

    std::cout << "Final Balance: " << shared_balance << "\n";
    return 0;
}


/*
it is a very simple only theory based implementation of lock*/