#include <iostream>
#include <vector>


int main(){
    int mem_pool = 1000;
    std::vector<int> arr = {10, 126};
    int value = arr[0];
    int reps = arr[1];
    int count = 0;
    int unallocated = 0;

    if (value * reps > mem_pool) {
        unallocated = reps - (mem_pool / value);
    }

    for (int i = 0; i < reps; ++i) {
        if (mem_pool >= value) {
            mem_pool -= value;
            count++;
        } else {
            break;
        }
    }

    std::cout << "Number of processes: " << count << std::endl;
    std::cout << "Space left: " << mem_pool << std::endl;
    std::cout << "Unallocated processes: " << unallocated << std::endl;

    return 0;
}

/*
just a toy like implementation of segregated table - where we already know amount of memory a these same 
processes take and segregate table into mutiple partition, and when let us say P1 arrives with requirment of 10 mb,
it is given a slice of segregated table to work within , to keep it isolated and running freely in requirment.*/