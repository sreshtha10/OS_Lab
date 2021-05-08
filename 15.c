#include<stdio.h>
#include<stdbool.h>

void findWaitingTime(int processes[], int n,int bt[], int wt[], int quantum){
	int rem_bt[n];
	for (int i = 0 ; i < n ; i++){
	    rem_bt[i] = bt[i];
	}
	int t = 0;
	while (1){
		bool done = true;
		for (int i = 0 ; i < n; i++){
			if (rem_bt[i] > 0){
				done = false;
				if (rem_bt[i] > quantum){
					t += quantum;
					rem_bt[i] -= quantum;
				}
				else{
					t = t + rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}
			}
		}
		if (done == true)
		break;
	}
}


void findTurnAroundTime(int processes[], int n,int bt[], int wt[], int tat[]) {
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}


void findavgTime(int processes[], int n, int bt[],int quantum){
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	findWaitingTime(processes, n, bt, wt, quantum);
	findTurnAroundTime(processes, n, bt, wt, tat);
    printf("  Process ID\tBurst Time\tWaiting Time\tTurnAround Time\n");
	for (int i=0; i<n; i++){
		total_wt += wt[i];
		total_tat += tat[i];
		printf("  %d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
	}
	printf("Average Turn Around Time = %.2f\nAverage Waiting Time = %.2f\n",(total_tat/(float)n),(total_wt/(float)n));
}


int main(){
	int n, quantum;
	printf("Enter the number of process -> ");
	scanf("%d",&n);
	int burst_time[n],processes[n];
	for(int i = 0;i<n;i++){
	    printf("Enter the process ID for process %d -> ",i+1);
	    scanf("%d",&processes[i]);
	    printf("Enter the burst time for process %d -> ",i+1);
	    scanf("%d",&burst_time[i]);
	}
	printf("Enter the time quantum -> ");
	scanf("%d",&quantum);
	findavgTime(processes, n, burst_time, quantum);
	return 0;
}
