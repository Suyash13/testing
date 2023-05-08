// S.R.T.F. Scheduling Policy
// By Suyash Pandey: 2020KUEC2045
#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
};

// Comparison function to sort the processes based on burst time
bool cmp(process a, process b)
{
    return a.burst_time < b.burst_time;
}

void SRTF(vector<process> processes)
{
    int n = processes.size();
    int current_time = 0, completed = 0, prev = 0;
    float total_wait_time = 0, total_turnaround_time = 0;

    // Priority queue to store the processes based on remaining burst time
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Sort the processes based on arrival time
    sort(processes.begin(), processes.end(), [](process a, process b)
         { return a.arrival_time < b.arrival_time; });

    cout << "PID\tA.T.\tB.T.\tC.T." << endl;
    while (completed != n)
    {
        for (int i = prev; i < n; i++)
        {
            if (processes[i].arrival_time <= current_time)
            {
                pq.push({processes[i].burst_time, processes[i].pid});
                prev++;
            }
            else
            {
                break;
            }
        }

        if (pq.empty())
        {
            current_time++;
            continue;
        }

        pair<int, int> curr = pq.top();
        pq.pop();

        int pid = curr.second;
        int burst_time = curr.first;

        total_wait_time += current_time - processes[pid].arrival_time;
        total_turnaround_time += current_time + burst_time - processes[pid].arrival_time;

        current_time += burst_time;
        completed++;

        cout << processes[pid].pid + 1 << "\t" << processes[pid].arrival_time << "\t" << processes[pid].burst_time << "\t" << current_time << endl;
    }

    float avg_wait_time = total_wait_time / n;
    float avg_turnaround_time = total_turnaround_time / n;
    cout << "Average Waiting Time: " << avg_wait_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
}

int main()
{
    // Input of Process IDs, Arrival Times and Burst Times
    vector<process> processes = {
        {0, 0, 5},
        {1, 1, 3},
        {2, 2, 8},
        {3, 3, 6},
        {4, 4, 1}};

    SRTF(processes);

    return 0;
}