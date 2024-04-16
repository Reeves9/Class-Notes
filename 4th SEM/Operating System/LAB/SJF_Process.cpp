#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Process {
    int id;
    int burstTime;
    int arrivalTime;
};

bool compareProcesses(Process a, Process b) {
    return (a.burstTime < b.burstTime);
}

void findWaitingTime(vector<Process>& processes, vector<int>& waitingTime) {
    int n = processes.size();
    vector<bool> isProcessed(n, false);
    waitingTime[0] = 0;

    for (int time = 0; time < n; time++) {
        int shortestIndex = -1;
        int minArrivalTime = numeric_limits<int>::max();

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && !isProcessed[i]) {
                if (processes[i].arrivalTime < minArrivalTime || (processes[i].arrivalTime == minArrivalTime && processes[i].burstTime < processes[shortestIndex].burstTime)) {
                    minArrivalTime = processes[i].arrivalTime;
                    shortestIndex = i;
                }
            }
        }

        if (shortestIndex != -1) {
            isProcessed[shortestIndex] = true;
            for (int i = 0; i < n; i++) {
                if (!isProcessed[i] && processes[i].arrivalTime <= time) {
                    waitingTime[i] += processes[shortestIndex].burstTime;
                }
            }
            time += processes[shortestIndex].burstTime;
        }
    }
}

void findTurnaroundTime(vector<Process>& processes, vector<int>& waitingTime, vector<int>& turnaroundTime) {
    int n = processes.size();
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = processes[i].burstTime + waitingTime[i];
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    vector<int> waitingTime(n), turnaroundTime(n);

    cout << "Enter the process details (ID, Burst Time, Arrival Time):\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processes[i].id >> processes[i].burstTime >> processes[i].arrivalTime;
    }

    sort(processes.begin(), processes.end(), compareProcesses);

    findWaitingTime(processes, waitingTime);
    findTurnaroundTime(processes, waitingTime, turnaroundTime);

    cout << "\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t\t" << processes[i].burstTime << "\t\t" << processes[i].arrivalTime
             << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\n";
    }

    return 0;
}