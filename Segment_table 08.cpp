#include<bits/stdc++.h>
// this header file includes all other header file in g++99,g++11 complier...
// so no need to declare any other header file...if you do so it may conflict at some point...
// but if you need any g++17 header file in your code you have to add it by yourself...
// but don't worry you won't need any of g++17 header file...
using namespace std;
int main()
{
    freopen("SegmentTable.txt","r",stdin);
    freopen("SegmentOutput.txt","w",stdout);

    long base[4]= {0},bound[4]= {0},base_to_bound[4]= {0},virtual_address=0;
    long segment=0,offset=0;
    string access[4]={""},access_input="";

    // try to maintain the variable size all to be same
    // if you use "long" once then make sure all other's are also be "long"
    // sometimes it may stops the looping conditions

    for(long i=0; i<4; i++)
    {
        cin>>base[i]>>bound[i]>>access[i];
        base_to_bound[i]=base[i]+bound[i];
    }

    cout<<"Base"<<"\t"<<"Bound"<<"\t"<<"Access"<<endl;
    for(long i=0; i<4; i++)
    {
        cout<<base[i]<<"\t"<<bound[i]<<"\t"<<access[i]<<endl;

    }

    long j=0;
    cin>>j;

    for(long k=0; k<j; k++)
    {
        cin>>virtual_address>>access_input;

        segment=virtual_address>>8;
        offset=virtual_address & 255;

        if(segment==0)
        {
            long base_offset=offset+base[0];
            if( base_offset>=base[0] && base_offset<=base_to_bound[0])
            {
                if(access[0]=="w")
                {
                    if(access_input==access[0])
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Write permission only"<<endl;
                    }
                    else
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Permission denied"<<endl;
                    }
                }
                if(access[0]=="r")
                {
                    if(access_input==access[0])
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Read permission only"<<endl;

                    }
                    else
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Permission denied"<<endl;
                    }
                }
            }
            else
            {
                cout<<"Wrong memory address"<<endl;
            }
        }
        else if(segment==1)
        {
            long base_offset=offset+base[1];
            if( base_offset>=base[1] && base_offset<=base_to_bound[1])
            {
                if(access[1]=="w")
                {
                    if(access_input==access[1])
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Write permission only"<<endl;

                    }
                    else
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Permission denied"<<endl;
                    }

                }
                if(access[1]=="r")
                {
                    if(access_input==access[1])
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Read permission only"<<endl;
                    }
                    else
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Permission denied"<<endl;
                    }
                }
            }
            else
            {
                cout<<"Wrong memory address"<<endl;
            }
        }
        else if(segment==2)
        {
            long base_offset=offset+base[2];
            if(base_offset>=base[2] && base_offset<=base_to_bound[2])
            {
                if(access[2]=="w")
                {
                    if(access_input==access[2])
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Write permission only"<<endl;
                    }
                    else
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Permission denied"<<endl;
                    }
                }
                if(access[2]=="r")
                {
                    if(access_input==access[0])
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Read permission only"<<endl;
                    }
                    else
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Permission denied"<<endl;

                    }
                }
            }
            else
            {
                cout<<"Wrong memory address"<<endl;
            }
        }
        else if(segment==3)
        {
            long base_offset=offset+base[3];
            if(base_offset>=base[3] && base_offset<=base_to_bound[3])
            {
                if(access[3]=="w")
                {
                    if(access_input==access[3])
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Write permission only"<<endl;
                    }
                    else
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Permission denied"<<endl;
                    }
                }
                if(access[3]=="r")
                {
                    if(access_input==access[3])
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Read permission only"<<endl;
                    }
                    else
                    {
                        cout<<"Physical address:"<<base_offset<<endl;
                        cout<<"Permission denied"<<endl;
                    }
                }
            }
            else
            {
                cout<<"Wrong memory address"<<endl;
            }
        }
        else
        {
            cout<<"Wrong memory address"<<endl;
        }

    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
