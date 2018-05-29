#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int ba[4],bo[4],seg[4];
    int v,s;
    int o,temp;
    string a[4],v_a;

    for(int i=0; i<4; i++)
    {
        cin>>ba[i]>>bo[i];
        cin>>a[i];
    }
    for(int i=0; i<4; i++)
    {
        seg[i]=ba[i]+bo[i];
    }
    while(cin>>v>>v_a)
    {
        s=v>>10;
        o=v&1023;

        if(s>=0&&s<=3)
        {
            temp=o+ba[s];
            if(temp>=ba[s]&&temp<=seg[s])
            {
                if(a[s]==v_a)
                {
                    cout<<"Access granted..."<<endl;
                }
                else if(a[s]=="RW")
                {
                    cout<<"Access granted..."<<endl;
                }
                else
                    cout<<"Access denied..."<<endl;
            }
            else
                cout<<"Access denied..."<<endl;
        }
        else
            cout<<"Access denied..."<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
