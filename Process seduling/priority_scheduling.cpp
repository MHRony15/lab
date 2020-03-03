#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,BT[20],WT[20],TaT[20],avwt=0,total_wait=0,i,j,p[20],priority[20],time=0;

    cout<<"Enter total number of processes:";
    cin>>n;
    cout<<"\nEnter Process Burst Time and priority\n";
    for(i=0;i<n;i++)
    {
        cin>>BT[i]>>priority[i];
        p[i]=i+1;

    }
    for(i=0;i<n;i++){
        for(int j= i+1;j<n;j++){
            if(priority[j]<priority[i]){
                swap(priority[i],priority[j]);
                swap(BT[i],BT[j]);
                swap(p[i],p[j]);
            }
        }
    }
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tCompletion Time";
    TaT[0]=0;
    for(i=0;i<n;i++){
        time=time+BT[i];
        TaT[i]=time;
        WT[i]=TaT[i]-BT[i];
        total_wait=total_wait+WT[i];
        cout<<"\nP["<<p[i]<<"]"<<"\t\t"<<BT[i]<<"\t\t"<<WT[i]<<"\t\t"<<TaT[i];
    }
            avwt=total_wait/n;

    cout<<"\n\nAverage Waiting Time:"<<avwt;
    return 0;
}


