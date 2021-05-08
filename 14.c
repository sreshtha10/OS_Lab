#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
typedef struct Process {
    int pid; // Process ID
    int bt; // Burst Time
    int art; // Arrival Time
}Process;


void findWaitingTime(Process proc[], int n,
                                int wt[])
{
    int rt[n];


    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;


    while (complete != n) {

        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) &&
            (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false) {
            t++;
            continue;
        }

        rt[shortest]--;


        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;


        if (rt[shortest] == 0) {


            complete++;
            check = false;


            finish_time = t + 1;


            wt[shortest] = finish_time -
                        proc[shortest].bt -
                        proc[shortest].art;

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        t++;
    }
}


void findTurnAroundTime(Process proc[], int n,
                        int wt[], int tat[])
{

    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

// Function to calculate average time
void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0,
                    total_tat = 0;


    findWaitingTime(proc, n, wt);


    findTurnAroundTime(proc, n, wt, tat);

    printf("  Process ID\tBurst Time\tWaiting Time\tTurnAround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n",proc[i].pid,proc[i].bt,wt[i],tat[i]);
    }

     printf("Average Turn Around Time = %.2f\nAverage Waiting Time = %.2f\n",(total_tat/(float)n),(total_wt/(float)n));
}


int main()
{
    int num;
    printf("Enter the number of processes -> ");
    scanf("%d",&num);
    Process proc[num];

    for(int i=0; i<num; i++)
    {
        printf("Process %d\n",i+1);
        printf("Enter the process ID -> ");
        scanf("%d",&proc[i].pid);
        printf("Enter the arrival time -> ");
        scanf("%d",&proc[i].art);
        printf("Enter the burst time -> ");
        scanf("%d",&proc[i].bt);
    }

    findavgTime(proc, num);
    return 0;
}
