// S.J.F. Scheduling Policy
// By Suyash Pandey: 2020KUEC2045
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, temp, tt = 0, min, d, i, j;
    float atat = 0, awt = 0, stat = 0, swt = 0;

    cout << "Enter the number of processes: " << endl;
    cin >> n;
    int at[n], bt[n], e[n], tat[n], wt[n], ct[n];

    for (i = 0; i < n; i++)
    {
        cout << "Enter the arrival time of process " << i + 1 << ": ";
        cin >> at[i];
    }
    for (i = 0; i < n; i++)
    {
        cout << "Enter the burst time of process " << i + 1 << ": ";
        cin >> bt[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    min = at[0];
    for (i = 0; i < n; i++)
    {
        if (min > at[i])
        {
            min = at[i];
            d = i;
        }
    }
    tt = min;
    e[d] = tt + bt[d];
    tt = e[d];

    for (i = 0; i < n; i++)
    {
        if (at[i] != min)
        {
            e[i] = bt[i] + tt;
            tt = e[i];
        }
    }
    for (i = 0; i < n; i++)
    {

        tat[i] = e[i] - at[i];
        stat = stat + tat[i];
        wt[i] = tat[i] - bt[i];
        swt = swt + wt[i];
        ct[i] = tat[i] + at[i];
    }
    atat = stat / n;
    awt = swt / n;
    cout << "P.I.D\tA.T.\tB.T.\tC.T.\tW.T.\tT.A.T.\n";

    for (i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
    }

    cout << "Average Waiting Time: " << awt << " Average Turnaround Time: " << atat;
}