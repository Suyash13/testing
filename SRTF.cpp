#include<iostream>

using namespace std;
int main()
{
    int AT[10],BT[10],x[10],WT[10],TAT[10],CT[10],i,j,smallest,count=0,time,n;
    double avg_WT=0,avg_TAT=0,end;

    cout<<"\nEnter the number of Processes: ";
    cin>>n;
    for (i=0;i<n;i++)
    {
        cout<<"enter Arival time P["<<i<<"]:";
        cin>>AT[i];
    }
    cout<<endl;
    for (i=0;i<n;i++)
    {
        cout<<"enter Brust time P["<<i<<"]:";
        cin>>BT[i];
    }
    for (i=0;i<n;i++)
        x[i]=BT[i];

    BT[9]=9999;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for (i=0;i<n;i++)
        {
            if(AT[i]<=time && BT[i]<BT[smallest] && BT[i]>0 )
                smallest=i;
        }
        BT[smallest]--;

        if(BT[smallest]==0)
        {
            count++;
            end=time+1;
            CT[smallest] = end;
            WT[smallest] = end - AT[smallest] - x[smallest];
            TAT[smallest] = end - AT[smallest];
        }
    }
    cout <<" Processes "<<"  "<< "Burst time "<<"  "<< "Arrival time "<< "\t"<<" Waiting time " <<"\t"<< " Turn around time"<<"  "<<" completion-time "<<"\n";

    for (i=0;i<n;i++)
    {
        cout << "   " << i+1 << "\t\t" << x[i] << "\t\t" << AT[i] << "\t\t" << WT[i] << "\t\t" << TAT[i] << "\t\t" << CT[i] <<endl;
        avg_WT = avg_WT + WT[i];
        avg_TAT = avg_TAT + TAT[i];
    }
    cout<<"\nAverage waiting time ="<<avg_WT<<endl<<"Average Turnaround time ="<<avg_TAT<<endl;
}
