#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    int id;
    int burstTime;
    int arrivalTime;
};

void findWaitingTime(vector<Process>& processes, vector<int>& waitingTime) {
    int n = processes.size();
    queue<Process> readyQueue;

    waitingTime[0] = 0;

    for (int i = 1; i < n; i++) {
        Process prev = processes[i - 1];
        Process curr = processes[i];

        if (curr.arrivalTime < prev.burstTime + waitingTime[i - 1]) {
            waitingTime[i] = prev.burstTime + waitingTime[i - 1] - curr.arrivalTime;
        } else {
            waitingTime[i] = 0;
        }

        readyQueue.push(curr);
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

    findWaitingTime(processes, waitingTime);
    findTurnaroundTime(processes, waitingTime, turnaroundTime);

    cout << "\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t\t" << processes[i].burstTime << "\t\t" << processes[i].arrivalTime
             << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\n";
    }

    return 0;
}