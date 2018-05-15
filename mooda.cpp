#include<bits/stdc++.h>
using namespace std;
class fcfs_alg
{
    int ar[10],exe[10],id[10];
    int n;
    void sort(int *,int *,int *);
public:
    void getdata();
    void display();
    void cal_wt_tt();
};
class sjf_alg
{
    int ar[10],exe[10],id[10];
    int n;
    void sort(int *,int *,int *);
public:
    void getdata();
    void display();
    void cal_wt_tt();
};
class rr_alg
{
    int ar[10],id[10],exe[10];
    int n,q;
    void sort(int *f,int *mid,int *last);
public:
    void getdata();
    void display();
    void cal_wt_tt();
};
class priority_alg
{
    int pr[10],id[10],exe[10],ar[10];
    int n;
    void sort(int*,int*,int*,int *);
public:
    void getdata();
    void display();
    void cal_wt_tt();
};
class npriority_alg
{
    int pr[10],id[10],exe[10],ar[10];
    int n;
    void sort(int*,int*,int*,int *);
public:
    void getdata();
    void display();
    void cal_wt_tt();
};
void npriority_alg::getdata()
{
    cout<<"How many process to be entered : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter execution,arrival time and priority of "<<i+1<<" process : ";
        cin>>exe[i]>>ar[i]>>pr[i];
        id[i]=i+1;
    }
}
void npriority_alg::display()
{
    cout<<endl<<"Process ID\tExecution time\tArrival Time \tPriority "<<endl;
    for(int i=0; i<n; i++)
        cout<<setw(5)<<id[i]<<setw(15)<<exe[i]<<setw(15)<<ar[i]<<setw(15)<<pr[i]<<endl;
}
void npriority_alg::sort(int *f,int *mid,int *last,int *ll)
{
    int temp;
    for(int y=0; y<n-1; y++)
    {
        for(int z=0; z<n-1; z++)
            if(f[z]>f[z+1])
            {
                temp=f[z];
                f[z]=f[z+1];
                f[z+1]=temp;
                temp=mid[z];
                mid[z]=mid[z+1];
                mid[z+1]=temp;
                temp=last[z];
                last[z]=last[z+1];
                last[z+1]=temp;
                temp=ll[z];
                ll[z]=ll[z+1];
                ll[z+1]=temp;
            }
    }
}
void npriority_alg::cal_wt_tt()
{
    int flag=1;
    int at=0,ind,wt,tnt,min,max=pr[0];
    float avg=0,avtnt=0;
    sort(ar,id,exe,pr);
    at=ar[0];
    sort(pr,id,exe,ar);
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
        at+=exe[ind];
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
void priority_alg::getdata()
{
    cout<<"How many process to be entered : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter execution,arrival time and priority of "<<i+1<<" process : ";
        cin>>exe[i]>>ar[i]>>pr[i];
        id[i]=i+1;
    }
}
void priority_alg::display()
{
    cout<<endl<<"Process ID\tExecution time\tArrival Time \tPriority "<<endl;
    for(int i=0; i<n; i++)
        cout<<setw(5)<<id[i]<<setw(15)<<exe[i]<<setw(15)<<ar[i]<<setw(15)<<pr[i]<<endl;
}
void priority_alg::sort(int *f,int *mid,int *last,int *ll)
{
    int temp;
    for(int y=0; y<n-1; y++)
    {
        for(int z=0; z<n-1; z++)
            if(f[z]>f[z+1])
            {
                temp=f[z];
                f[z]=f[z+1];
                f[z+1]=temp;
                temp=mid[z];
                mid[z]=mid[z+1];
                mid[z+1]=temp;
                temp=last[z];
                last[z]=last[z+1];
                last[z+1]=temp;
                temp=ll[z];
                ll[z]=ll[z+1];
                ll[z+1]=temp;
            }
    }
}
void priority_alg::cal_wt_tt()
{
    int flag=1;
    int at=0,ind,wt,tnt,min,max=pr[0];
    float avg=0,avtnt=0;
    sort(ar,id,exe,pr);
    at=ar[0];
    sort(pr,id,exe,ar);
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
        at+=exe[ind];
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
void rr_alg::getdata()
{
    cout<<"How many process to be entered : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter execution time and arrival time of process "<<i+1<<" : ";
        cin>>exe[i]>>ar[i];
        id[i]=i+1;
    }
    cout<<"Enter Quantum slice : ";
    cin>>q;
}
void rr_alg::display()
{
    cout<<endl<<"Process ID\tExecution time\tArrival Time "<<endl;
    for(int i=0; i<n; i++)
        cout<<setw(5)<<i+1<<setw(15)<<exe[i]<<setw(15)<<ar[i]<<endl;
}
void rr_alg::sort(int *f,int *mid,int *last)
{
    int temp;
    for(int y=0; y<n-1; y++)
    {
        for(int z=0; z<n-1; z++)
            if(f[z]>f[z+1])
            {
                temp=f[z];
                f[z]=f[z+1];
                f[z+1]=temp;
                temp=mid[z];
                mid[z]=mid[z+1];
                mid[z+1]=temp;
                temp=last[z];
                last[z]=last[z+1];
                last[z+1]=temp;
            }
    }
}

void rr_alg::cal_wt_tt()
{
    int exe2[10],flag=1,flag1=0;
    int at=0,wt,tnt;
    float avg=0,avtnt=0;
    sort(ar,id,exe);
    for(int i=0; i<n; i++)
        exe2[i]=exe[i];
    at=ar[0];
    cout<<"\nProcess ID \tWaiting time \tTurn Around time "<<endl;
    while(flag)
    {
        for(int i=0; i<n; i++)
        {
            if(at<ar[i]||id[i]<0)
                continue;
            flag1=1;
            at+=q;
            exe[i]-=q;
            if(exe[i]<=0)
            {
                at+=exe[i];
                wt=at-exe2[i]-ar[i];
                tnt=at-ar[i];
                cout<<setw(5)<<id[i]<<setw(15)<<wt<<setw(15)<<tnt<<endl;
                id[i]=-1;
                avg+=wt;
                avtnt+=tnt;
            }
        }
        if(flag1==0)
            at++;
        flag1=flag=0;
        for(int k=0; k<n; k++)
            if(id[k]!=-1)
                flag=1;
    }
    avg=avg/(float)n;
    avtnt/=(float)n;
    cout<<"\nAverage Waiting time     : "<<avg;
    cout<<"\nAverage turn Around time : "<<avtnt<<endl;
}
void sjf_alg::getdata()
{
    cout<<"How many processes to be entered : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter execution time and arrival time of "<<i+1<<" process : ";
        cin>>exe[i]>>ar[i];
        id[i]=i+1;
    }
}
void sjf_alg::display()
{
    cout<<endl<<"Process ID\tExecution time\tArrival Time "<<endl;
    for(int i=0; i<n; i++)
        cout<<setw(5)<<i+1<<setw(15)<<exe[i]<<setw(15)<<ar[i]<<endl;
}
void sjf_alg::sort(int *f,int *m,int *l)
{
    int temp;
    for(int y=0; y<n-1; y++)
    {
        for(int z=0; z<n-1; z++)
            if(f[z]>f[z+1])
            {
                temp=f[z];
                f[z]=f[z+1];
                f[z+1]=temp;
                temp=l[z];
                l[z]=l[z+1];
                l[z+1]=temp;
                temp=m[z];
                m[z]=m[z+1];
                m[z+1]=temp;
            }
    }
}
void sjf_alg::cal_wt_tt()
{
    int flag=1;
    int at=0,ind,wt,tnt,min,max=exe[0];
    float avg=0,avtnt=0;
    sort(ar,exe,id);
    for(int i=1; i<n; i++)
    {
        if(max<exe[i])
            max=exe[i];
    }
    at=ar[0];
    min=max+1;
    cout<<"\nProcess ID \tWaiting time \tTurn Around time "<<endl;
    while(flag)
    {
        for(int i=0; i<n; i++)
        {
            if(at>=ar[i]&&min>exe[i]&&id[i]!=-1)
            {
                ind=i;
                min=exe[i];
            }
        }
        if(id[ind]==-1)
        {
            at++;
            continue;
        }
        wt=at-ar[ind];
        at+=exe[ind];
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
void fcfs_alg::getdata()
{
    cout<<"How many process to be entered : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter brust time and arrival time of process "<<i+1<<" : ";
        cin>>exe[i]>>ar[i];
        id[i]=i+1;
    }
}
void fcfs_alg::display()
{
    cout<<endl<<"Process ID\tbrust  time\tArrival Time "<<endl;
    for(int i=0; i<n; i++)
        cout<<setw(5)<<i+1<<setw(15)<<exe[i]<<setw(15)<<ar[i]<<endl;
}
void fcfs_alg::sort(int *f,int *m,int *l)
{
    int temp;
    for(int y=0; y<n-1; y++)
    {
        for(int z=0; z<n-1; z++)
            if(f[z]>f[z+1])
            {
                temp=f[z];
                f[z]=f[z+1];
                f[z+1]=temp;
                temp=l[z];
                l[z]=l[z+1];
                l[z+1]=temp;
                temp=m[z];
                m[z]=m[z+1];
                m[z+1]=temp;
            }
    }
}
void fcfs_alg::cal_wt_tt()
{
    int wt,tnt,temp;
    float avg=0,avtnt=0;
    sort(ar,exe,id);
    temp=ar[0];
    cout<<"\nProcess id \tWaiting time \tTurn around time "<<endl;
    for(int i=0; i<n; i++)
    {
        if(ar[i]>temp)
        {
            wt=0;
            temp=ar[i];
        }
        else
            wt=temp-ar[i];
        avg+=wt;
        temp+=exe[i];
        tnt=temp-ar[i];
        avtnt+=tnt;
        cout<<setw(5)<<id[i]<<setw(15)<<wt<<setw(15)<<tnt<<endl;
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
        cout<<"1.fcfs"<<endl<<"2.sjf"<<endl<<"3.rr"<<endl<<"4.prority"<<endl<<"5.non prority"<<endl<<"6.end"<<endl;
        cout<<"Enter choice"<<endl;
        int c;
        cin>>c;
        if(c==1)
        {
            fcfs_alg fcfs;
            fcfs.getdata();
            fcfs.display();
            fcfs.cal_wt_tt();
        }
        else if(c==2)
        {
            sjf_alg sjf;
            sjf.getdata();
            sjf.display();
            sjf.cal_wt_tt();
        }
        else if(c==3)
        {
            rr_alg rr;
            rr.getdata();
            rr.display();
            rr.cal_wt_tt();
        }
        else if(c==4)
        {
            priority_alg priority;
            priority.getdata();
            priority.display();
            priority.cal_wt_tt();
        }
        else if(c==5)
        {
            npriority_alg npriority;
            npriority.getdata();
            npriority.display();
            npriority.cal_wt_tt();
        }
        else
            break;
    }
    return 0;
    return 0;
}
