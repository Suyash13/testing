#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> bt, wt, tat;
    int n;
    cout<<"Enter number of processes:"<<endl;
    cin>>n;
    cout<<"Enter the respective burst times of the processes:"<<endl;
    for(int  i = 0; i<n; i++)
    {
        int b;
        cin>>b;
        bt.push_back(b);
    }

    wt.push_back(0);
    for(int i = 1; i<n; i++)
    {
        int w = 0;
        w = bt[i-1] + wt[i-1];
        wt.push_back(w);
    }

    for(int i = 0; i<n; i++)
    {
        int t = 0;
        t = wt[i]+bt[i];
        tat.push_back(t);
    }

    cout<<"P IDs\t"<<"B.T.\t"<<"W.T.\t"<<"T.A.T."<<endl<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<i+1<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }
    return 0;
}