#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,BT[20],WT[20],TaT[20],avwt=0,total_wait=0,i,j,time=0;

    cout<<"Enter total number of processes:";
    cin>>n;

    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>BT[i];
        time=time+BT[i];
        TaT[i]=time;
        WT[i]=time-BT[i];
        total_wait=total_wait+WT[i];
    }
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++){
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<BT[i]<<"\t\t"<<WT[i]<<"\t\t"<<TaT[i];
    }
            avwt=total_wait/n;

    cout<<"\n\nAverage Waiting Time:"<<avwt;
    return 0;
}
