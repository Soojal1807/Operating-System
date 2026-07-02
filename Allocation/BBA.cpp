#include <iostream>
#include <vector>

int PowerOf2(int n){
    int p = 1;
    while (p < n) {
        p *= 2;
    }
    return p;
}


int main() {
    int t_memory = 1024;
    std::vector<int> processes = {24, 56, 224, 103};
    int t_internal_frag = 0;

    for (int req : processes) {
        int allocated = PowerOf2(req);
        
        if (allocated > t_memory) {
            std::cout << req << " - skip\n";
        } else {
            int frag = allocated - req;
            t_memory -= allocated;
            t_internal_frag += frag;
            
            std::cout << req << " - " << allocated << " - " << frag << "\n";
        }
    }

    std::cout << "Total memory left: " << t_memory << "\n";
    std::cout << "Total internal fragmentation: " << t_internal_frag << "\n";

    return 0;
}

/* this is a simple implementation of buddy allocation, 
it accepts process , first step is to check if process needs more memory then we 
can provide, after that we try to allocate it memory based on power of 2 , since 
computer is based of binary any calculation based on 2^n is easy, so after we find next biggest digit
to memeory we need we allocate it and accept internal fragmentation, thing is we do not care much about it
because it is an accepted trade-of for faster performance. It is not very practical where memory is tight
we cannot use it and there will be lot of waste of memory , but it can be used where we know for fact requirments will not be much,
maybe like small cli based applications.*/
