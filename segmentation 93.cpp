#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int base[4]={},bound[4]={},seg_size[4]={},v_mem=0,segment=0,offset=0,temp=0;
    string access[4]={},v_access="\0";

    for(int i=0; i<4; i++)
    {
        cin>>base[i]>>bound[i]>>access[i];
        seg_size[i]=base[i]+bound[i];
    }
    while(cin>>v_mem>>v_access&&(v_mem>-1&&v_mem<1024))
    {
        segment=v_mem>>8;
        offset=v_mem&255;

        if(segment>=0&&segment<=3)
        {
            temp=offset+base[segment];
            if(temp>=base[segment]&&temp<=seg_size[segment])
            {
                if(access[segment]==v_access)
                {
                    cout<<"permission granted..."<<endl;
                }
                else if(access[segment]=="RW")
                {
                    cout<<"permission granted..."<<endl;
                }
                else
                    cout<<"permission denied..."<<endl;
            }
            else
                cout<<"permission denied..."<<endl;
        }
        else
            cout<<"permission denied..."<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
