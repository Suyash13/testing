// Round Robin Scheduling Policy
// By: Suyash Pandey (2020KUEC2045)
#include <iostream>
using namespace std;
int main()
{
    int i, n, time, remaining, temps = 0, time_quantum;
    int wt = 0, tat = 0;
    cout << "Enter the number of processes: " << endl;
    cin >> n;
    remaining = n;
    int at[n];
    int bt[n];
    int rt[n];

    cout << "Enter the Arrival and Burst Time for Respective processes: \nArrival Times followed by burst times:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> at[i];
        cin >> bt[i];
        rt[i] = bt[i];
    }
    cout << "Enter the value of Time Quanta: " << endl;
    cin >> time_quantum;

    cout << "\n\nProcess\t:   T.A.T.\t:  W.T.\n\n";
    for (time = 0, i = 0; remaining != 0;)
    {
        if (rt[i] <= time_quantum && rt[i] > 0)
        {
            time += rt[i];

            rt[i] = 0;
            temps = 1;
        }

        else if (rt[i] > 0)
        {
            rt[i] -= time_quantum;

            time += time_quantum;
        }

        if (rt[i] == 0 && temps == 1)
        {
            remaining--;
            printf("P{%d}\t:\t%d\t:\t%d\n", i, time - at[i], time - at[i] - bt[i]);
            cout << endl;

            wt += time - at[i] - bt[i];
            tat += time - at[i];
            temps = 0;
        }

        if (i == n - 1)
            i = 0;
        else if (at[i] <= time)
            i++;
        else
            i = 0;
    }
    cout << "Average Waiting Time: " << wt * 1.0 / n << endl;
    cout << "Average TurnAround Time: " << tat * 1.0 / n << endl;
    return 0;
}