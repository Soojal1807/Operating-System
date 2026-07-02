#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct Process{
    int id;
    int arrivalTime;
    int burstTime;
    int exitTime;
    int turnaroundTime;
    int waitTime;   
};


bool compareArrival(Process p1, Process p2){
    return p1.arrivalTime < p2.arrivalTime;
}


void calculateFCFS(vector<Process>& processes){
    int n = processes.size();
    sort(processes.begin(), processes.end(), compareArrival);
    
    int currentTime = 0;
    for(int i = 0; i < n; i++){
        if(currentTime < processes[i].arrivalTime){
            currentTime = processes[i].arrivalTime;
        }

        processes[i].exitTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].exitTime - processes[i].arrivalTime;
        processes[i].waitTime = processes[i].turnaroundTime - processes[i].burstTime;

        currentTime = processes[i].exitTime;
    }
}



void display(const vector<Process>& processes){
    for (const auto& p : processes) {
        cout << p.id << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t" 
             << p.exitTime << "\t" << p.turnaroundTime << "\t" << p.waitTime << "\n";
    }
}


int main(){git 
    vector<Process> processes ={
        {1, 0, 4, 0, 0, 0},
        {2, 5, 2, 0, 0, 0}, 
        {3, 6, 1, 0, 0, 0}
    };

    calculateFCFS(processes);
    display(processes);

    return 0;
}

