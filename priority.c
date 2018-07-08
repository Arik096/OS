#include<stdio.h>
int main()
{
    int i,j,n;
    float pno[10],prior[10],bt[10],wt[10],tt[10],w1=0,t1=0,s;
    float aw,at;
    printf("enter the number of processes:");
    scanf("%d",&n);
    printf("Enter the burst time of processes:");
    for(i=0; i<n; i++)
    {
    scanf("%f",&bt[i]);
    }
    printf("Enter the priority of processes");
    for(i=0; i<n; i++)
    {
        scanf("%f",&prior[i]);
        pno[i]=i+1;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(prior[i]<prior[j])
            {
                s=prior[i];
                prior[i]=prior[j];
                prior[j]=s;

                s=bt[i];
                bt[i]=bt[j];
                bt[j]=s;

                s=pno[i];
                pno[i]=pno[j];
                pno[j]=s;
            }
        }
    }
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
    printf(" \n bt \t prior \t wt \t tt \n");
    for(i=0; i<n; i++)
        printf("%.0f \t % .0f\t %.0f\t %.0f\n",bt[i],prior[i],wt[i],tt[i]);
    printf("aw=%f \t at=%f \n",aw,at);
    return 0;
}
















/*
1. Start
2. Declare the array size
3. Read the number of processes to be inserted
4. Read the Priorities of processes
5. sort the priorities and Burst times in ascending order
5. calculate the waiting time of each process
   wt[i+1]=bt[i]+wt[i]
6. calculate the turnaround time of each process
   tt[i+1]=tt[i]+bt[i+1]
6. Calculate the average waiting time and average turnaround time.
7. Display the values
8. Stop
*/
