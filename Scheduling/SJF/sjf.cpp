#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;


struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int exitTime;
    int turnaroundTime;
    int waitTime;
    bool isDone = false; 
};


void calculateSJF(vector<Process>& processes) {
    int n = processes.size();
    int currentTime = 0;
    int Count = 0;

    while (Count < n) {
        int index = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !processes[i].isDone) {
                if (processes[i].burstTime < minBurst) {
                    minBurst = processes[i].burstTime;
                    index = i;
                }
            }
        }

        if (index != -1) {
            currentTime += processes[index].burstTime;
            processes[index].exitTime = currentTime;
            processes[index].turnaroundTime = processes[index].exitTime - processes[index].arrivalTime;
            processes[index].waitTime = processes[index].turnaroundTime - processes[index].burstTime;
            processes[index].isDone = true;
            Count++;
        } else {
            currentTime++;
        }
    }
}


void display(const vector<Process>& processes) {
    for (const auto& p : processes) {
        cout << p.id << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t" 
             << p.exitTime << "\t" << p.turnaroundTime << "\t" << p.waitTime << "\n";
    }
}


int main() {
    vector<Process> processes = {
        {1, 0, 4, 0, 0, 0},
        {2, 5, 2, 0, 0, 0}, 
        {3, 6, 1, 0, 0, 0}
    };

    calculateSJF(processes);
    display(processes);

    return 0;
}