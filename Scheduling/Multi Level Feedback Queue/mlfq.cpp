#include <iostream>
#include <vector>
#include <queue>

struct Job {
    int value;
    int loop_rotations = 0; 
};

int main() {
    std::vector<int> array = {120, 30, 160, 45, 80};
    
    std::queue<Job> high_priority;
    std::queue<Job> low_priority;

    for (int num : array) {
        high_priority.push({num, 0});
    }

    while (!high_priority.empty()) {
        Job current = high_priority.front();
        high_priority.pop();
        
        std::cout << current.value << " -> " << (current.value - 50) << "\n";
        current.value -= 50;

        if (current.value > 0) {
            low_priority.push(current);
        }
    }

    while (!low_priority.empty()) {
        Job current = low_priority.front();
        low_priority.pop();

        std::cout << current.value << " -> " << (current.value - 50) << "\n";
        current.value -= 50;

        if (current.value > 0) {
            current.lp_rotations++;
            
            if (current.loop_rotations < 2) {
                low_priority.push(current);
            } else {
                current.loop_rotations = 0;
                high_priority.push(current);
            }
        }
    }

    if (!high_priority.empty()) {
        while (!high_priority.empty()) {
            Job current = high_priority.front();
            high_priority.pop();
            
            std::cout << current.value << " -> " << (current.value - 50) << "\n";
            current.value -= 50;
        }
    }

    return 0;
}



// this is just toy like MLFQ. loop rotation is just a cheaper gimick i used to just figure out switching "ofcourse it doesnt work this way"
// starvation is problem this code has if you see 120 and 160 they got booted hard. 
// I can add - timer like function just like real life kernel one.
// negatives are issue.
// A problem should not run more than it needs to run.

