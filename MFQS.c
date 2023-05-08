// Multilevel Feedback Queue Scheduling Algorithm
// By: Suyash Pandey (2020KUEC2045)

#include <stdio.h>
struct process
{
    char name;
    int AT, BT, WT, TAT, RT, CT;
} Q1[10], Q2[10], Q3[10]; // Three Queues

int n;

// Processes sorted on the basis of Arrival Time
void sortByArrival()
{
    struct process temp;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (Q1[i].AT > Q1[j].AT)
            {
                temp = Q1[i];
                Q1[i] = Q1[j];
                Q1[j] = temp;
            }
        }
    }
}

int main()
{

    int i, j, k = 0, r = 0, time = 0, tq1 = 3, tq2 = 6, flag = 0;
    char c;
    printf("Enter no of processes: ");
    scanf("%d", &n);

    // Input of Arrival and Burst Times of the processes
    for (i = 0, c = 'A'; i < n; i++, c++)
    {
        Q1[i].name = c;
        printf("\nEnter the Arrival Time and Burst Time of process %c: ", Q1[i].name);
        scanf("%d%d", &Q1[i].AT, &Q1[i].BT);
        Q1[i].RT = Q1[i].BT;
    }

    // Processes sorted on the basis of arrival times
    sortByArrival();


    time = Q1[0].AT;
    printf("Process in first queue (Priority Queue): ");
    printf("\nProcess\t\tB.T.\t\tW.T.\t\tT.A.T.\t\t");
    for (i = 0; i < n; i++)
    {
        //Loops through each process in q1
        if (Q1[i].RT <= tq1)
        {

            time += Q1[i].RT; // Add remaining running time of process to present time
            Q1[i].RT = 0; //RT set to 0 as process is complete
            Q1[i].WT = time - Q1[i].AT - Q1[i].BT; 
            Q1[i].TAT = time - Q1[i].AT;
            printf("\n%c\t\t%d\t\t%d\t\t%d", Q1[i].name, Q1[i].BT, Q1[i].WT, Q1[i].TAT);
        }
        else
        {
            Q2[k].WT = time; //Process added to Q2 as it has higher burst time
            time += tq1; // time moves by tq1
            Q1[i].RT -= tq1; // Remaining reduced by tq1
            Q2[k].BT = Q1[i].RT; //Burst time is set to new remaining time
            Q2[k].RT = Q2[k].BT; 
            Q2[k].name = Q1[i].name;
            k = k + 1; // TO add the process to end of Q2
            flag = 1;
        }
    }

    if (flag == 1)
    {
        printf("\nProcess in second queue following RR with Time Quanta = 6 secs");
        printf("\nProcess\t\tB.T.\t\tW.T.\t\tT.A.T.\t\t");
    }

    for (i = 0; i < k; i++)
    {
        if (Q2[i].RT <= tq2)
        {
            time += Q2[i].RT;
            Q2[i].RT = 0;
            Q2[i].WT = time - tq1 - Q2[i].BT;
            Q2[i].TAT = time - Q2[i].AT;
            printf("\n%c\t\t%d\t\t%d\t\t%d", Q2[i].name, Q2[i].BT, Q2[i].WT, Q2[i].TAT);
        }
        else
        {
            Q3[r].AT = time;
            time += tq2;
            Q2[i].RT -= tq2;
            Q3[r].BT = Q2[i].RT;
            Q3[r].RT = Q3[r].BT;
            Q3[r].name = Q2[i].name;
            r = r + 1;
            flag = 2;
        }
    }


    {
        if (flag == 2)
            printf("\nProcess in third queue following FCFS Scheduling Algorithm: ");
    }

    // Completion Time Calculation
    for (i = 0; i < r; i++)
    {
        if (i == 0)
            Q3[i].CT = Q3[i].BT + time - tq1 - tq2;
        else
            Q3[i].CT = Q3[i - 1].CT + Q3[i].BT;
    }

    //Turnaround Time and Waiting Time calculation
    for (i = 0; i < r; i++)
    {
        Q3[i].TAT = Q3[i].CT;
        Q3[i].WT = Q3[i].TAT - Q3[i].BT;
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t", Q3[i].name, Q3[i].BT, Q3[i].WT, Q3[i].TAT);
    }
}
