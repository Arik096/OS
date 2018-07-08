#include<stdio.h>
int main()
{
    int i,j,n;
    float bt[10],wt[10],tt[10],w1=0,t1=0;
    float aw,at;
    printf("enter no. of processes:\n");
    scanf("%d",&n);
    printf("enter the burst time of processes:");
    for(i=0; i<n; i++)
        scanf("%f",&bt[i]);
    for(i=0; i<n; i++)
    {
        wt[0]=0;
        tt[0]=bt[0];
        wt[i+1]=bt[i]+wt[i];
        tt[i+1]=tt[i]+bt[i+1];
        w1=w1+wt[i];
        t1=t1+tt[i];
    }
    aw=w1/n;
    at=t1/n;
    printf("\nbt\t wt\t tt\n");
    for(i=0; i<n; i++)
        printf("%.0f\t %.0f\t %.0f\n",bt[i],wt[i],tt[i]);
    printf("aw=%f\nat=%f\n",aw,at);
    return 0;
}






/*
1. Start
2. Declare the array size
3. Read the number of processes to be inserted
4. Read the Burst times of processes
5. calculate the waiting time of each process
   wt[i+1]=bt[i]+wt[i]
6. calculate the turnaround time of each process
   tt[i+1]=tt[i]+bt[i+1]
7. Calculate the average waiting time and average turnaround time.
8. Display the values
9. Stop
*/
