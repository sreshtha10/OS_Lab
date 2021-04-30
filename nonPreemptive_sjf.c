
// Non preemptive Shortest Job First Scheduling Algorithm.
#include <stdio.h>
#define MAX 30

int main(int argc, char const *argv[])
{
    int n, process[MAX],burstTime[MAX],waitingTime[MAX],turnAroundTime[MAX];
    float averageWaitingTime, averageTurnAroundTime;
    int totalWaitingTime =0 , totalTurnAroundTime = 0;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    printf("Enter the process id and burst time of processes\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&process[i],&burstTime[i]);
    }

    /* Sorting the processes on the basis of burst time because the process with the shortest burst time will be processed first.*/

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(burstTime[j]>burstTime[j+1]){
                int tmp = burstTime[j];
                burstTime[j]=burstTime[j+1];
                burstTime[j+1]=tmp ;

                tmp =process[j];
                process[j]=process[j+1];
                process[j+1]=tmp;
            }
        }
    }


    printf(" Process  BurstTime  WaitingTime  TurnaroundTime \n");
    int i,j;
    for (i = 0; i < n; i++)
    {
        waitingTime[i]=0;
        turnAroundTime[i]=0;
        for(j=0;j<i;j++){
            waitingTime[i]=waitingTime[i]+burstTime[j];
        }
        turnAroundTime[i]=waitingTime[i]+burstTime[j];
        totalWaitingTime= totalWaitingTime+waitingTime[i];
        totalTurnAroundTime= totalTurnAroundTime+turnAroundTime[i];
        printf("%d\t %d\t\t %d\t\t %d \n",process[i],burstTime[i],waitingTime[i],turnAroundTime[i]);
    }



    averageWaitingTime = totalWaitingTime/n;
    averageTurnAroundTime = totalTurnAroundTime/n;
    printf("Average waiting time= %f\n",averageWaitingTime);
    printf("Average turn around time= %f",averageTurnAroundTime);
    return 0;
}
