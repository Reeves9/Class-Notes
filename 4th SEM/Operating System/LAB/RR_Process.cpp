#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Process {
    int id;
    int burstTime;
    int arrivalTime;
};

void findWaitingTime(vector<Process>& processes, vector<int>& waitingTime, int timeQuantum) {
    int n = processes.size();
    vector<int> remainingTime(n, 0);
    queue<int> readyQueue;

    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].burstTime;
    }

    int currentTime = 0;
    bool allProcessesCompleted = false;

    while (!allProcessesCompleted) {
        allProcessesCompleted = true;

        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                allProcessesCompleted = false;

                if (remainingTime[i] > timeQuantum) {
                    currentTime += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                    readyQueue.push(i);
                } else {
                    currentTime += remainingTime[i];
                    waitingTime[i] = currentTime - processes[i].burstTime - processes[i].arrivalTime;
                    remainingTime[i] = 0;
                }
            }
        }

        while (!readyQueue.empty()) {
            int currentProcess = readyQueue.front();
            readyQueue.pop();

            if (remainingTime[currentProcess] > 0) {
                readyQueue.push(currentProcess);
                break;
            }
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
    int n, timeQuantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    vector<Process> processes(n);
    vector<int> waitingTime(n), turnaroundTime(n);

    cout << "Enter the process details (ID, Burst Time, Arrival Time):\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processes[i].id >> processes[i].burstTime >> processes[i].arrivalTime;
    }

    findWaitingTime(processes, waitingTime, timeQuantum);
    findTurnaroundTime(processes, waitingTime, turnaroundTime);

    cout << "\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t\t" << processes[i].burstTime << "\t\t" << processes[i].arrivalTime
             << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\n";
    }

    return 0;
}