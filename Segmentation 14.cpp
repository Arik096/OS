#include<bits/stdc++.h>
// this header file includes all other header file in g++99,g++11 complier...
// so no need to declare any other header file...if you do so it may conflict at some point...
// but if you need any g++17 header file in your code you have to add it by yourself...
// but don't worry you won't need any of g++17 header file...
using namespace std;

int Input()
{
    int vAddress;

    cout<<"Enter Virtual Address(10 Bit): ";
    cin>>vAddress;

    return vAddress;
}
void translation(int *Seg,int *Off,int *vAddress)
{
    *Seg= *vAddress>>8;
    *Off= *vAddress & 255;

    cout<<endl<<"Virtual Address: "<<*vAddress<<endl;
    cout<<endl<<"Segment: "<<*Seg<<endl;
    cout<<endl<<"Offset: "<<*Off<<endl;
}
int main()
{

    int Segment=0,Offset=0,vAddress=0,Base=0,Bound=0,a;

    while(1)
    {
        vAddress=Input();

        if(vAddress==-1)
            break;

        translation(&Segment,&Offset,&vAddress);

        if (Segment == 0)
        {
            Base=0;
            Bound=256;
            string Access= "R";

            if(Offset > Bound)
            {
                cout<<"No Access Permission"<<endl<<endl;
            }
            else if(Offset < Bound)
            {
                cout<<endl<<"Base: "<<Base<<endl<<endl<<"Bound: "<<Bound<<endl;

                a = Offset + Base;

                cout<<endl<<"Physical Address: "<<a<<endl;
                cout<<endl<<"Access: Read Only"<<endl<<endl;
            }

        }
        else if (Segment == 1)
        {
            Base=250;
            Bound=512;
            string Access= "RW";

            if(Offset > Bound)
            {
                cout<<"No Access Permission"<<endl<<endl;
            }
            else if(Offset < Bound)
            {
                cout<<endl<<"Base: "<<Base<<endl<<endl<<"Bound: "<<Bound<<endl;

                a = Offset + Base;

                cout<<endl<<"Physical Address: "<<a<<endl;
                cout<<endl<<"Access: Read and Write"<<endl<<endl;
            }

        }
        else if (Segment == 2)
        {
            Base=400;
            Bound=768;
            string Access= "R";

            if(Offset > Bound)
            {
                cout<<"No Access Permission"<<endl<<endl;
            }
            else if(Offset < Bound)
            {
                cout<<endl<<"Base: "<<Base<<endl<<endl<<"Bound: "<<Bound<<endl;

                a = Offset + Base;

                cout<<endl<<"Physical Address: "<<a<<endl;
                cout<<endl<<"Access: Read Only"<<endl<<endl;
            }

        }
        else if (Segment == 3)
        {
            Base=800;
            Bound=1024;
            string Access= "R";

            if(Offset > Bound)
            {
                cout<<"No Access Permission"<<endl<<endl;
            }
            else if(Offset<Bound)
            {
                cout<<endl<<"Base: "<<Base<<endl<<endl<<"Bound: "<<Bound<<endl;

                a = Offset + Base;

                cout<<endl<<"Physical Address: "<<a<<endl;
                cout<<endl<<"Access: Write Only"<<endl<<endl;
            }
            else if (Segment > 3)
            {
                cout<<"Invalid Input"<<endl<<endl;
            }
        }
        else
            cout<<"Invalid Input"<<endl<<endl;
    }
    return 0;
}
