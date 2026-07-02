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