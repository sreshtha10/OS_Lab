#include<stdio.h>

int main() {

  int n;

  printf("Enter total num of processes -> ");
  scanf("%d", & n);

  int bt[n], p[n], wt[n], tat[n], pr[n];

  for (int i = 0; i < n; i++) {

    printf("Enter the process id for process %d -> ", i + 1);
    scanf("%d", & p[i]);

    printf("Enter the burst time for process %d -> ", i + 1);
    scanf("%d", & bt[i]);

    printf("Enter the priority for process %d -> ", i + 1);
    scanf("%d", & pr[i]);
  }

  int pos;
  for (int i = 0; i < n; i++) {
    pos = i;
    for (int j = i + 1; j < n; j++) {
      if (pr[j] < pr[pos])
        pos = j;
    }

    int temp = pr[i];
    pr[i] = pr[pos];
    pr[pos] = temp;

    temp = bt[i];
    bt[i] = bt[pos];
    bt[pos] = temp;

    temp = p[i];
    p[i] = p[pos];
    p[pos] = temp;
  }

  wt[0] = 0;

  int total_wt = 0, total_tat = 0;

  for (int i = 1; i < n; i++) {
    wt[i] = 0;
    for (int j = 0; j < i; j++)
      wt[i] += bt[j];
    total_wt += wt[i];
  }

  printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++) {
    tat[i] = bt[i] + wt[i];
    total_tat += tat[i];
    printf(" %d\t\t %d\t\t %d\t\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
  }

  printf("Average Turn Around Time = %.2f\nAverage Waiting Time = %.2f\n", (total_tat / (float) n), (total_wt / (float) n));
  return 0;
}
