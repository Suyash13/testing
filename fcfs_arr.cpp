#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the number of processes: ";
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    vector<int> ct(n), tat(n), wt(n), at(n);
    cout << "Enter the arrival time for the " << n << " processes:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> at[i];
    }
    cout << "Enter the burst time for the respective " << n << " processes:\n";
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        v.push_back(make_pair(at[i], m));
    }
    sort(v.begin(), v.end());
    int k = v[0].first;
    cout << "A.T. (in order)\t"
         << "B.T.\t\t"
         << "C.T.\t\t"
         << "T.A.T.\t\t"
         << "W.T." << endl;

    for (int i = 0; i < n; i++)
    {
        ct[i] = k + v[i].second;
        k = ct[i];
    }
    int tats = 0;
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - v[i].first;
        tats += tat[i];
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - v[i].second;
        ans += wt[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << "\t\t" << v[i].second << "\t\t" << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    }
    float tat1 = tats / n;
    float q = ans / n;
    cout << "\nAverage Waiting Time: " << q << endl;
    cout << "\nAverage Turn Around Time: " << tat1 << endl;
}