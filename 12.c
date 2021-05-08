// First Come First Serve Scheduling Algorithm.
#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    int process[n], burstTime[n],arrivalTime[n], turnAroundTime[n],waitingTime[n], completionTime[n];




    printf("Enter the process id, arrival time and burst time\n");
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&process[i],&arrivalTime[i],&burstTime[i]);
    }

    /* sorting in with respect to arrival time because first arrived proccess will be
    processed first*/

    for(int i =0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arrivalTime[j] > arrivalTime[j+1]){
                // swap
                int tmp = arrivalTime[j];
                arrivalTime[j] = arrivalTime[j+1];
                arrivalTime[j+1] = tmp;

                tmp = burstTime[j];
                burstTime[j] = burstTime[j+1];
                burstTime[j+1] = tmp;


                tmp = process[j];
                process[j] = process[j+1];
                process[j+1] = tmp;
            }
        }
    }


    // calculating completion time for each process.
    int timer = 0;
    for(int i = 0;i<n;i++){
        if(arrivalTime[i] > timer ){
            timer = arrivalTime[i];
        }

        completionTime[i] = timer+burstTime[i];
        timer += burstTime[i];
    }



    // calculating turnaround time and waiting time
    float totalTurnAroundTime = 0, totalWaitingTime = 0;
    for(int i = 0;i<n;i++){
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
        totalTurnAroundTime += turnAroundTime[i];

        waitingTime[i] = turnAroundTime[i] - burstTime[i];
        totalWaitingTime += waitingTime[i];
    }


    // printing all the details with avg turnaround time and avg waiting time

    printf("\n ProcessId     ArrivalTime     BurstTime     TurnAroundTime     WaitingTime\n");
    for(int i=0;i<n;i++){
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",process[i],arrivalTime[i],burstTime[i],turnAroundTime[i],waitingTime[i]);
    }

    printf("Average Turnaround Time = %f\nAverage Waiting Time = %f",totalTurnAroundTime/n,totalWaitingTime/n);
}



