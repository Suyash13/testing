#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

struct Process {
    int pid;
    int burstTime;
    int arrivalTime;
    int priority;

    Process(int pid, int burstTime, int arrivalTime, int priority) {
        this->pid = pid;
        this->burstTime = burstTime;
        this->arrivalTime = arrivalTime;
        this->priority = priority;
    }
};

struct ComparePriority {
    bool operator()(Process& p1, Process& p2) {
        return p1.priority > p2.priority;
    }
};

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes;
    for (int i = 0; i < n; i++) {
        int burstTime, arrivalTime, priority;
        cout << "Enter burst time, arrival time, and priority for process " << i+1 << ": ";
        cin >> burstTime >> arrivalTime >> priority;
        processes.push_back(Process(i+1, burstTime, arrivalTime, priority));
    }

    // Sort the processes by arrival time
    sort(processes.begin(), processes.end(), [](Process& p1, Process& p2) {
        return p1.arrivalTime < p2.arrivalTime;
    });

    // Use a priority queue to schedule the processes by priority
    priority_queue<Process, vector<Process>, ComparePriority> pq;
    int totalTime = 0;
    vector<int> completionTime(n), waitingTime(n), turnaroundTime(n);
    int i = 0;
    while (i < n || !pq.empty()) {
        if (!pq.empty()) {
            Process p = pq.top();
            pq.pop();
            completionTime[p.pid-1] = totalTime + p.burstTime;
            waitingTime[p.pid-1] = totalTime - p.arrivalTime;
            turnaroundTime[p.pid-1] = completionTime[p.pid-1] - p.arrivalTime;
            totalTime = completionTime[p.pid-1];
        }
        else {
            totalTime = processes[i].arrivalTime;
        }
        while (i < n && processes[i].arrivalTime <= totalTime) {
            pq.push(processes[i]);
            i++;
        }
    }

    // Display the Gantt chart in tabular form
    cout << "\nGantt Chart:" << endl;
    cout << "|";
    for (int i = 0; i < n; i++) {
        Process& p = processes[i];
        for (int j = 0; j < p.burstTime; j++) {
            cout << " P" << p.pid << " |";
        }
    }
    cout << endl;
    cout << "0";
    for (int i = 0; i < n; i++) {
        Process& p = processes[i];
        for (int j = 0; j < p.burstTime; j++) {
            cout << setw(4) << completionTime[p.pid-1] - p.burstTime + j + 1;
        }
    }
    cout << setw(4) << totalTime << endl;

    // Display the average waiting time and average turnaround time
    double avgWaitingTime = accumulate(waitingTime.begin(), waitingTimeend(), 0.0) / n;
double avgTurnaroundTime = accumulate(turnaroundTime.begin(), turnaroundTime.end(), 0.0) / n;
cout << "\nAverage Waiting Time: " << avgWaitingTime << endl;
cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
return 0;
}