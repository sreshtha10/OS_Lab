#include<stdio.h>

int mat[10][6];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void arrangeArrival(int num, int mat[][6])
{
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num-i-1; j++)
        {
            if(mat[j][1] > mat[j+1][1])
            {
                for(int k=0; k<5; k++)
                {
                    swap(&mat[j][k],&mat[j+1][k]);
                }
            }
        }
    }
}

void completionTime(int num, int mat[][6])
{
    int temp, val;
    mat[0][3] = mat[0][1] + mat[0][2];
    mat[0][5] = mat[0][3] - mat[0][1];
    mat[0][4] = mat[0][5] - mat[0][2];

    for(int i=1; i<num; i++)
    {
        temp = mat[i-1][3];
        int low = mat[i][2];
        for(int j=i; j<num; j++)
        {
            if(temp >= mat[j][1] && low >= mat[j][2])
            {
                low = mat[j][2];
                val = j;
            }
        }
        mat[val][3] = temp + mat[val][2];
        mat[val][5] = mat[val][3] - mat[val][1];
        mat[val][4] = mat[val][5] - mat[val][2];
        for(int k=0; k<6; k++)
        {
            swap(&mat[val][k], &mat[i][k]);
        }
    }
}

int main()
{
    int num, temp;

    printf("Enter the number of processes -> ");
    scanf("%d",&num);

    for(int i=0; i<num; i++)
    {
        printf("Process %d\n",i+1);
        printf("Enter the process ID -> ");
        scanf("%d",&mat[i][0]);
        printf("Enter the arrival time -> ");
        scanf("%d",&mat[i][1]);
        printf("Enter the burst time -> ");
        scanf("%d",&mat[i][2]);
    }

    arrangeArrival(num, mat);
    completionTime(num, mat);
    printf("  Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time\n");

    int totalTA = 0;
    int totalWT =0;
    for(int i =0;i<num;i++){
        totalTA += mat[i][4];
        totalWT += mat[i][3];
    }
    for(int i=0; i<num; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",mat[i][0],mat[i][1],mat[i][2],mat[i][3],mat[i][4]);
    }


    printf("Average Turn Around Time = %.2f\nAverage Waiting Time = %.2f\n",(totalTA/(float)num),(totalWT/(float)num));



}
