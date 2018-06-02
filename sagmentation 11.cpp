#include<bits/stdc++.h>
using namespace std;

int base[4],bound[4],seg_size[4],v_mem,segment,offset,temp;
string access[4],v_access;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int i=0;
    do
    {
        cin>>base[i]>>bound[i]>>access[i];
        seg_size[i]=base[i]+bound[i];
        i++;
    }while(i<4);

    while(cin>>v_mem>>v_access)
    {
        segment=v_mem>>10;
        offset=v_mem&1023;

        if(segment>=0&&segment<=3)
        {
            temp=offset+base[segment];
            if(temp>=base[segment]&&temp<=seg_size[segment])
            {
                if(access[segment]==v_access)
                {
                    cout<<"Memory access granted..."<<endl;
                }
                else
                    cout<<"Memory access denied..."<<endl;
            }
            else
                cout<<"Memory access denied..."<<endl;
        }
        else
            cout<<"Memory access denied..."<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
