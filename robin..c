#include<stdio.h>
int main()
{
    int st[10],bt[10],wt[10],tat[10],n,tq;
    int i,count=0,swt=0,stat=0,temp,sq=0;
    float awt=0.0,atat=0.0;

    printf("Enter number of processes:");
    scanf("%d",&n);
    printf("Enter burst time for sequences:");
    for(i=0; i<n; i++)
    {
        scanf("%d",&bt[i]);
        st[i]=bt[i];
    }
    printf("Enter time quantum:");
    scanf("%d",&tq);
    while(1)
    {
        for(i=0,count=0; i<n; i++)
        {
            temp=tq;
            if(st[i]==0)
            {
                count++;
                continue;
            }
            if(st[i]>tq)
                st[i]=st[i]-tq;
            else if(st[i]>=0)
            {
                temp=st[i];
                st[i]=0;
            }
            sq=sq+temp;
            tat[i]=sq;
        }
        if(n==count)
            break;
    }
    for(i=0; i<n; i++)
    {
        wt[i]=tat[i]-bt[i];
        swt=swt+wt[i];
        stat=stat+tat[i];
    }
    awt=(float)swt/n;
    atat=(float)stat/n;
    printf("Bt \t Wt \t Tt");
    for(i=0; i<n; i++)
        printf("\n%d\t %d\t %d",bt[i],wt[i],tat[i]);
    printf("\nAvg wait time is %f Avg turn around time is %f",awt,atat);
    return 0;
}












/*
1. Start
2. Declare the array size
3. Read the number of processes to be inserted
4. Read the burst times of the processes
5. Read the Time Quantum
6. if the burst time of a process is greater than time Quantum then subtract time quantum form the burst time
   Else Assign the burst time to time quantum.
7.calculate the average waiting time and turn around time of the processes.
8. Display the values
9. Stop
*/
