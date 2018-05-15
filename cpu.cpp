/**
    * CPU scheduling Algorithms
    * Non-preemptive First Come First Serve(FCFS)
    * Non-preemptive Shortest Job First(SJF)
    * Preeptive Round-Robin
    * priority preeptive
    * priority non-preeptive
    * 14/05/2018
**/
#include<bits/stdc++.h>
using namespace std;
void Non_preemptive_First_Come_First_ServeFCFS_sort(int *at,int *bt,int *id,int n)
{
    int temp_var;
    for(int y=0; y<n-1; y++)
    {
        for(int z=0; z<n-1; z++)
            if(at[z]>at[z+1])
            {
                temp_var=at[z];
                at[z]=at[z+1];
                at[z+1]=temp_var;
                temp_var=id[z];
                id[z]=id[z+1];
                id[z+1]=temp_var;
                temp_var=bt[z];
                bt[z]=bt[z+1];
                bt[z+1]=temp_var;
            }
    }
}
void Non_preemptive_Shortest_Job_First_SJF_sort(int *at,int *bt,int *id,int n)
{
    int temp_var;
    for(int y=0; y<n-1; y++)
    {
        for(int z=0; z<n-1; z++)
            if(at[z]>at[z+1])
            {
                temp_var=at[z];
                at[z]=at[z+1];
                at[z+1]=temp_var;
                temp_var=id[z];
                id[z]=id[z+1];
                id[z+1]=temp_var;
                temp_var=bt[z];
                bt[z]=bt[z+1];
                bt[z+1]=temp_var;
            }
    }
}
void Preeptive_Round_Robin_sort(int *at,int *id,int *bt,int n)
{
    int temp_var;
    for(int y=0; y<n-1; y++)
    {
        for(int z=0; z<n-1; z++)
            if(at[z]>at[z+1])
            {
                temp_var=at[z];
                at[z]=at[z+1];
                at[z+1]=temp_var;
                temp_var=id[z];
                id[z]=id[z+1];
                id[z+1]=temp_var;
                temp_var=bt[z];
                bt[z]=bt[z+1];
                bt[z+1]=temp_var;
            }
    }
}
void priority_preeptive_sort(int *f,int *mid,int *last,int *ll,int n)
{
    int temp_var;
    for(int y=0; y<n-1; y++)
    {
        for(int z=0; z<n-1; z++)
            if(f[z]>f[z+1])
            {
                temp_var=f[z];
                f[z]=f[z+1];
                f[z+1]=temp_var;
                temp_var=mid[z];
                mid[z]=mid[z+1];
                mid[z+1]=temp_var;
                temp_var=last[z];
                last[z]=last[z+1];
                last[z+1]=temp_var;
                temp_var=ll[z];
                ll[z]=ll[z+1];
                ll[z+1]=temp_var;
            }
    }
}
void priority_non_preeptive_sort(int *f,int *mid,int *last,int *ll,int n)
{
    int temp_var;
    for(int y=0; y<n-1; y++)
    {
        for(int z=0; z<n-1; z++)
            if(f[z]>f[z+1])
            {
                temp_var=f[z];
                f[z]=f[z+1];
                f[z+1]=temp_var;
                temp_var=mid[z];
                mid[z]=mid[z+1];
                mid[z+1]=temp_var;
                temp_var=last[z];
                last[z]=last[z+1];
                last[z+1]=temp_var;
                temp_var=ll[z];
                ll[z]=ll[z+1];
                ll[z+1]=temp_var;
            }
    }
}
void Non_preemptive_First_Come_First_ServeFCFS()
{
    int n,i;
    int wt[100]= {0},bt[100]= {0},at[100]= {0},tat[100]= {0},ct[100]= {0},id[100]= {0};
    float awt=0,atat=0;
    cout<<"Enter Number of processes: ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Arrival Time["<<i+1<<"]: ";
        cin>>at[i];
        cout<<"Brust Time["<<i+1<<"]: ";
        cin>>bt[i];
        id[i]=i+1;
    }
    Non_preemptive_First_Come_First_ServeFCFS_sort(at,bt,id,n);
    wt[0]=0;
    atat=bt[0];
    tat[0]=bt[0];
    ct[0]=bt[0];
    int btt=bt[0];
    for(i=1; i<n; i++)
    {
        btt=btt+bt[i];
        ct[i]=btt;
        tat[i]=ct[i]-at[i];
        atat=atat+tat[i];
        wt[i]=tat[i]-bt[i];
        awt=awt+wt[i];
    }
    atat=atat/n;
    awt=awt/n;

    printf("P.NO.\tA.T.\tB.T.\tC.T.\tT.A.T\tW.T.\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("Average Waiting Time: %.2f \n",awt);
    printf("Average Turn Around Time: %.2f \n",atat);
}
void Non_preemptive_Shortest_Job_First_SJF()
{
    int at[100]= {0},bt[100]= {0},ct[100]= {0},wt[100]= {0},ta[100]= {0},tat[100]= {0},id[100]= {0};
    int n,i,k,pc=0,j=0,tn=0,c;
    cout<<"Enter Number of processes: ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Arrival Time["<<i+1<<"]: ";
        cin>>at[i];
        cout<<"Brust Time["<<i+1<<"]: ";
        cin>>bt[i];
        id[i]=i+1;
    }
    Non_preemptive_Shortest_Job_First_SJF_sort(at,bt,id,n);
    float awt=0,atat=0;
    for(i=0; i<n; i++)
    {
        ct[i]=-1;
        ta[i]=bt[i];
    }
    while(pc!=n)
    {
        c=0;
        for(i=0; i<n; i++)
            if(ct[i]<0&&at[i]<=tn)
                c++;
        if(c==0)
            tn++;
        else
        {
            j=0;
            while(at[j]>tn||ct[j]>0)
                j++;
            for(k=j+1; k<n; k++)
                if(at[k]<=tn&&ct[k]<0&&bt[j]>bt[k])
                    j = k;
            if(ct[j]<0)
            {
                tn=tn+bt[j];
                ct[j]=tn;
                tat[j]=ct[j]-at[j];
                wt[j]=tat[j]-bt[j];
                awt=awt+wt[j];
                bt[j]=0;
                atat=atat+tat[j];
                pc++;
            }
        }
    }
    atat=atat/n;
    awt=awt/n;
    printf("\nPA.N.\tA.T.\tB.T.\tC.T.\tT.A.T.\tW.T.\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],ta[i],ct[i],tat[i],wt[i]);
    }
    printf("Average Waiting Time: %.2f \n",awt);
    printf("Average Turn Around Time: %.2f \n",atat);

}
void Preeptive_Round_Robin()
{
    int at[100],bt[100],ct[100]= {0},qt,rqi[100]= {0},c=0,st,flg=0,tm=0,noe=0,pnt=0,btm[50]= {0},tt,wt,n,id[100]= {0};
    float att=0, awt=0;
    cout<<"Enter Number of processes:";
    cin>>n;
    for(int x=0; x<n; x++)
    {
        cout<<"Arrival Time["<<x+1<<"]: ";
        cin>>at[x];
        cout<<"Brust Time["<<x+1<<"]: ";
        cin>>bt[x];
        btm[x]=bt[x];
        id[x]=x+1;
    }
    cout<<"\nEnter time quantum:";
    cin>>qt;
    Preeptive_Round_Robin_sort(at,id,bt,n);
    do
    {
        if(flg==0)
        {
            st=at[0];
            if(btm[0]<=qt)
            {
                tm=st+btm[0];
                btm[0]=0;
                for(int x=pnt+1; x<n; x++)
                {
                    if(at[x]<=tm)
                    {
                        rqi[noe]=x+1;
                        noe++;
                    }
                }
            }
            else
            {
                btm[0]=btm[0]-qt;
                tm=st+qt;
                for(int x=pnt+1; x<n; x++)
                {
                    if(at[x]<=tm)
                    {
                        rqi[noe]=x+1;
                        noe++;
                    }
                }
                rqi[noe]=pnt+1;
                noe++;
            }
        }
        else
        {
            pnt=rqi[0]-1;
            st=tm;
            for(int x=0; x<noe && noe!=1; x++)
            {
                rqi[x]=rqi[x+1];
            }
            noe--;
            if(btm[pnt]<=qt)
            {
                tm=st+btm[pnt];
                btm[pnt]=0;
                for(int x=pnt+1; x<n; x++)
                {
                    int fl=0;
                    for(int y=0; y<noe; y++)
                    {
                        if(rqi[y]==x+1)
                        {
                            fl++;
                        }
                    }
                    if(at[x]<=tm && fl==0 && btm[x]!=0)
                    {
                        rqi[noe]=x+1;
                        noe++;
                    }
                }
            }
            else
            {
                btm[pnt]=btm[pnt]-qt;
                tm=st+qt;
                for(int x=pnt+1; x<n; x++)
                {
                    int fl=0;
                    for(int y=0; y<noe; y++)
                    {
                        if(rqi[y]==x+1)
                        {
                            fl++;
                        }
                    }
                    if(at[x]<=tm && fl==0 && btm[x]!=0)
                    {
                        rqi[noe]=x+1;
                        noe++;
                    }
                }
                rqi[noe]=pnt+1;
                noe++;
            }
        }
        if(btm[pnt]==0)
        {
            ct[pnt]=tm;
        }
        flg++;
    }
    while(noe!=0);
    cout<<"\n\nPROCESS\t AT\t BT\t CT\t TT\t WT\n";
    for(int x=0; x<n; x++)
    {
        tt=ct[x]-at[x];
        wt=tt-bt[x];
        cout<<x+1<<" \t "<<at[x]<<" \t "<<bt[x]<<" \t "<<ct[x]<<" \t "<<tt<<" \t "<<wt<<"\n";
        awt=awt+wt;
        att=att+tt;
    }
    printf("Average Waiting Time: %.2f \n",awt/n);
    printf("Average Turn Around Time: %.2f \n",att/n);
}
void priority_preeptive()
{
    int pr[10],id[10],bt[10],ar[10];
    int n;
    cout<<"Enter Number of processes: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Arrival Time["<<i+1<<"]: ";
        cin>>ar[i];
        cout<<"Brust Time["<<i+1<<"]: ";
        cin>>bt[i];
        cout<<"Prority["<<i+1<<"]: ";
        cin>>pr[i];
        id[i]=i+1;
    }
    cout<<endl<<"Process ID\tBrust time\tArrival Time \tPriority "<<endl;
    for(int i=0; i<n; i++)
        cout<<setw(5)<<id[i]<<setw(15)<<bt[i]<<setw(15)<<ar[i]<<setw(15)<<pr[i]<<endl;
    int flag=1;
    int at=0,ind,wt,tnt,min,max=pr[0];
    float avg=0,avtnt=0;
    priority_preeptive_sort(ar,id,bt,pr,n);
    at=ar[0];
    priority_preeptive_sort(pr,id,bt,ar,n);
    for(int i=1; i<n; i++)
        if(max<pr[i])
            max=pr[i];
    min=max+1;
    cout<<"\nProcess ID \tWaiting time \tTurn Around time "<<endl;
    while(flag)
    {
        for(int i=0; i<n; i++)
        {
            if(at>=ar[i]&&min>pr[i]&&id[i]>0)
            {
                ind=i;
                min=pr[i];
            }
        }
        if(id[ind]==-1)
        {
            at++;
            continue;
        }
        wt=at-ar[ind];
        at+=bt[ind];
        avg+=wt;
        tnt=at-ar[ind];
        avtnt+=tnt;
        cout<<setw(5)<<id[ind]<<setw(15)<<wt<<setw(15)<<tnt<<endl;
        id[ind]=-1;
        min=max+1;
        flag=0;
        for(int k=0; k<n; k++)
            if(id[k]!=-1)
                flag=1;
    }
    avg=avg/(float)n;
    avtnt/=(float)n;
    cout<<"\nAverage Waiting time     : "<<avg;
    cout<<"\nAverage turn Around time : "<<avtnt<<endl;
}

void priority_non_preeptive()
{
    int pr[10],id[10],bt[10],ar[10];
    int n;
    cout<<"Enter Number of processes: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Arrival Time["<<i+1<<"]: ";
        cin>>ar[i];
        cout<<"Brust Time["<<i+1<<"]: ";
        cin>>bt[i];
        cout<<"Prority["<<i+1<<"]: ";
        cin>>pr[i];
        id[i]=i+1;
    }
    cout<<endl<<"Process ID\tBrust time\tArrival Time \tPriority "<<endl;
    for(int i=0; i<n; i++)
        cout<<setw(5)<<id[i]<<setw(15)<<bt[i]<<setw(15)<<ar[i]<<setw(15)<<pr[i]<<endl;
    int flag=1;
    int at=0,ind,wt,tnt,min,max=pr[0];
    float avg=0,avtnt=0;
    priority_non_preeptive_sort(ar,id,bt,pr,n);
    at=ar[0];
    priority_non_preeptive_sort(pr,id,bt,ar,n);
    for(int i=1; i<n; i++)
        if(max<pr[i])
            max=pr[i];
    min=max+1;
    cout<<"\nProcess ID \tWaiting time \tTurn Around time "<<endl;
    while(flag)
    {
        for(int i=0; i<n; i++)
        {
            if(at>=ar[i]&&min>pr[i]&&id[i]>0)
            {
                ind=i;
                min=pr[i];
            }
        }
        if(id[ind]==-1)
        {
            at++;
            continue;
        }
        wt=at-ar[ind];
        at+=bt[ind];
        avg+=wt;
        tnt=at-ar[ind];
        avtnt+=tnt;
        cout<<setw(5)<<id[ind]<<setw(15)<<wt<<setw(15)<<tnt<<endl;
        id[ind]=-1;
        min=max+1;
        flag=0;
        for(int k=0; k<n; k++)
            if(id[k]!=-1)
                flag=1;
    }
    avg=avg/(float)n;
    avtnt/=(float)n;
    cout<<"\nAverage Waiting time     : "<<avg;
    cout<<"\nAverage turn Around time : "<<avtnt<<endl;
}
int main()
{
    while(1)
    {
        int choice;

        cout<<endl;
        cout<<"CPU scheduling Algorithms"<<endl;
        cout<<"||---------------------------------------------------||"<<endl;
        cout<<"  1. Non-preemptive First Come First Serve(FCFS)"<<endl;
        cout<<"  2. Non-preemptive Shortest Job First(SJF)"<<endl;
        cout<<"  3. Preeptive Round-Robin"<<endl;
        cout<<"  4. priority preeptive"<<endl;
        cout<<"  5. priority non-preeptive"<<endl;
        cout<<"  6. Exit"<<endl;
        cout<<"||---------------------------------------------------||"<<endl<<endl;
        cout<<"Enter your choice: ";

        cin>>choice;

        if(choice==1)
            Non_preemptive_First_Come_First_ServeFCFS();
        else if(choice==2)
            Non_preemptive_Shortest_Job_First_SJF();
        else if(choice==3)
            Preeptive_Round_Robin();
        else if(choice==4)
            priority_preeptive();
        else if(choice==5)
            priority_non_preeptive();
        else if(choice==6)
            break;
        else
            cout<<"Wrong choice...please try again..."<<endl<<endl;
    }
    return 0;
}
