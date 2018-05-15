#include<stdio.h>
#include<stdlib.h>


int main()
{

   int choice;
   printf("Which scheduling algorithm you want to perform?\n\n");
   printf("1. First Come First Serve(FCFS)\n");
   printf("2. Shortest Job First(SJF)\n");
   printf("3. Priority Scheduling(Non-Preemptive)\n");
   printf("4. Priority Scheduling(Preemptive)\n");
   printf("5. Round Robin Scheduling\n");
   scanf("%d", &choice);

   switch(choice)
   {
   case 1:
    {
        printf("FCFS Scheduling\n");

        int n,AT[5],BT[5],t[5],w[5],gc[5],i,m, CT[5],j, p[10]={1,2,3,4,5,6,7,8,9,10};
        float att=0,awt=0;


        printf("Enter the number of process: ");
        scanf("%d",&n);

        for(i=0;i<10;i++)
        {
            w[i]=0, t[i]=0, CT[i]=0;
        }

        printf("Enter the arrival times and burst times: \n");
        for(i=0;i<n;i++)
        {
            scanf("%d%d", &AT[i], &BT[i]);
        }

        CT[0]=BT[0];

        for(j=1; j<n; j++)
            CT[j]=CT[j-1]+BT[j];

        for(i=0;i<n;i++)
        {
            t[i]=CT[i]-AT[i];
            w[i]=t[i]-BT[i];
            awt=awt+w[i];
            att=att+t[i];
        }

        awt =awt/n;
        att=att/n;

        printf("\n\tProcess\tWaiting time\tTurn arround time\tCompletion time\n");


        for(i=0;i<n;i++)
        {
            printf("\tp%d\t\t%d\t\t%d\t%d\n",i+1,w[i],t[i], CT[i]);
        }

        printf("The average waiting time is %f\n",awt);
        printf("The average turn around time is %f\n",att);

        break;
    }

   case 2:
    {
        printf("SJF Scheduling\n");

        int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},gc[10];
        int bt[10],temp,j,AT[10],wt[10],tt[10];
        float att=0,awt=0;;
        printf("\nEnter the No. of processes :");
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            printf("\tEnter the arrival time & burst time of %d process :",i+1);
            scanf(" %d%d",&AT[i], &bt[i]);
        }

        gc[0]=AT[0]+bt[0];


        for(i = 1; i < n; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                if(bt[i]>bt[j])
                {
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                    temp=bt[i];
                    bt[i]=bt[j];
                    bt[j]=temp;
                    temp=AT[i];
                    AT[i]=AT[j];
                    AT[j]=temp;
                }
            }
        }


        for(j=1;j<n;j++)
        {
            gc[j]=gc[j-1]+bt[j];
        }


        for(i=0;i<n;i++)
        {
            tt[i]=gc[i]-AT[i];
            wt[i]=tt[i]-bt[i];
            awt=awt+wt[i];
            att=att+tt[i];
        }

        awt =awt/n;
        att=att/n;

        for(i = 0; i < n; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                if(p[i]>p[j])
                {
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                    temp=wt[i];
                    wt[i]=wt[j];
                    wt[j]=temp;
                    temp=tt[i];
                    tt[i]=tt[j];
                    tt[j]=temp;;
                    temp=gc[i];
                    gc[i]=gc[j];
                    gc[j]=temp;
                }
            }
        }

        printf("\n\tProcess\tWaiting time\tTurn arround time\tCompletion time\n");


        for(i=0;i<n;i++)
        {
            printf("\tp%d\t\t%d\t\t%d\t\t%d\n",p[i],wt[i],tt[i], gc[i]);
        }

        printf("The average waiting time is %f\n",awt);
        printf("The average turn around time is %f\n",att);

        break;
   }

   case 3:
    {
        printf("Priority Scheduling(Non-preemptive)\n");
        int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
        printf("Enter Total Number of Process:");
        scanf("%d",&n);

        printf("\nEnter Burst Time and Priority\n");
        for(i=0;i<n;i++)
        {
            printf("\nP[%d]\n",i+1);
            printf("Burst Time:");
            scanf("%d",&bt[i]);
            printf("Priority:");
            scanf("%d",&pr[i]);
            p[i]=i+1;
        }


        for(i=0;i<n;i++)
        {
            pos=i;
            for(j=i+1;j<n;j++)
            {
                if(pr[j]<pr[pos])
                    pos=j;
            }

            temp=pr[i];
            pr[i]=pr[pos];
            pr[pos]=temp;

            temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;

            temp=p[i];
            p[i]=p[pos];
            p[pos]=temp;
        }

        wt[0]=0;

        for(i=1;i<n;i++)
        {
            wt[i]=0;
            for(j=0;j<i;j++)
                wt[i]+=bt[j];

            total+=wt[i];
        }

        avg_wt=total/n;
        total=0;

        printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
        for(i=0;i<n;i++)
        {
            tat[i]=bt[i]+wt[i];
            total+=tat[i];
            printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
        }

        avg_tat=total/n;
        printf("\n\nAverage Waiting Time=%d",avg_wt);
        printf("\nAverage Turnaround Time=%d\n",avg_tat);

        break;
    }

   case 4:
    {
        printf("Priority Scheduling(Preemptive)\n");
        int n;

        printf("Enter the no. of processes: ");

        scanf("%d",&n);

        int id[n],bt[n],wt[n],tat[n],p[n],i,j,temp;

        for(i=0;i<n;i++)

        {

        id[i]=i+1;

        printf("Enter process %d burst time: ",i+1);

        scanf("%d",&bt[i]);

        printf("Enter process %d priority: ",i+1);

        scanf("%d",&p[i]);

        }

        for(i=0;i<n;i++)

        {

        for(j=i+1;j<n;j++)

        {

        if(p[i]>p[j])

        {

        temp=p[i];

        p[i]=p[j];

        p[j]=temp;

        temp=bt[i];

        bt[i]=bt[j];

        bt[j]=temp;

        temp=id[i];

        id[i]=id[j];

        id[j]=temp;

        }

        }

        wt[i]=0;

        }

        for(i=0;i<n;i++)

        {

        for(j=0;j<i;j++)

        {

        wt[i]=wt[i]+bt[j];

        }

        tat[i]=wt[i]+bt[i];

        }

        float avwt=0,avtat=0;

        printf("Process\tP\tBT\tWT\tTAT\n");

        for(i=0;i<n;i++)

        {

        printf("%d\t%d\t%d\t%d\t%d\n",id[i],p[i],bt[i],wt[i],tat[i]);

        avwt=avwt+wt[i];

        avtat=avtat+tat[i];

        }

        avwt=avwt/n;

        avtat=avtat/n;

        printf("Average Waiting Time: %f\n",avwt);

        printf("\nAverage Turnaround Time: %f",avtat);
        break;
        }


    case 5:
    {
        printf("Round Robin Scheduling\n");

        int count,j,n,time,remain,flag=0,time_quantum;
        int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
        printf("Enter Total Process:\t ");
        scanf("%d",&n);
        remain=n;
        for(count=0;count<n;count++)
        {
        printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1);
        scanf("%d",&at[count]);
        scanf("%d",&bt[count]);
        rt[count]=bt[count];
        }
        printf("Enter Time Quantum:\t");
        scanf("%d",&time_quantum);
        printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
        for(time=0,count=0;remain!=0;)
        {
        if(rt[count]<=time_quantum && rt[count]>0)
        {
        time+=rt[count];
        rt[count]=0;
        flag=1;
        }
        else if(rt[count]>0)
        {
        rt[count]-=time_quantum;
        time+=time_quantum;
        }
        if(rt[count]==0 && flag==1)
        {
        remain--;
        printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
        wait_time+=time-at[count]-bt[count];
        turnaround_time+=time-at[count];
        flag=0;
        }
        if(count==n-1)
        count=0;
        else if(at[count+1]<=time)
        count++;
        else
        count=0;
        }
        printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
        printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);

        break;
        }

        default:
        printf("Error!");

        break;

    }
    return 0;
}

