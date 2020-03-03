#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,Hole[100],temp_hole1[100],temp_hole2[100],p,ind[100],ind2[100],in=0,pn,proc[100];
    cout<<"Enter the number of hole: ";
    cin>>h;
    cout<<"Enter the Hole size of :\n";
    for(int i=1;i<=h;i++){
        cout<<"h"<<i<<": ";
        cin>>Hole[i];
        temp_hole1[i]=Hole[i];
        temp_hole2[i]=Hole[i];
        ind[i]=i;
        ind2[i]=i;
    }
    cout<<"Enter the  number of Processes :";
    cin>>pn;
    cout<<"Enter the   Processes size of: "<<endl;
    for(int i=1;i<=pn;i++){
        cout<<"P["<<i<<"]: ";
            cin>>proc[i];
        }
    cout<<endl<<"First Fit "<<endl;
    cout<<"--------------------------------------------------"<<endl<<endl;
    for(int i = 1 ;i<=pn;i++){
        for(int j = 1 ;j<=h;j++){
            if(proc[i]<=Hole[j]){
                cout<<"P["<<i<<"] --> Hole["<<j<<"]"<<endl;
                Hole[j]=0;
                break;
            }

        }
    }
    cout<<endl<<"Best Fit "<<endl;
    cout<<"--------------------------------------------------"<<endl<<endl;
    for(int i=1;i<=pn;i++){
            for(int j=i;j<=h;j++){
                if(temp_hole1[i]>temp_hole1[j]){
                    swap(temp_hole1[i],temp_hole1[j]);
                    swap(ind[i],ind[j]);
                }
            }
    }
    for(int i = 1 ;i<=pn;i++){
        for(int j = 1 ;j<=h;j++){
            if(proc[i]<=temp_hole1[j]){
                cout<<"P["<<i<<"] --> Hole["<<ind[j]<<"]"<<endl;
                temp_hole1[j]=0;
                break;
            }
        }
    }
    cout<<endl<<"Wost Fit "<<endl;
    cout<<"--------------------------------------------------"<<endl<<endl;
    for(int i=1;i<=pn;i++){
            for(int j=i;j<=h;j++){
                if(temp_hole2[i]>temp_hole2[j]){
                    swap(temp_hole2[i],temp_hole2[j]);
                    swap(ind2[i],ind2[j]);
                }
            }
    }
    for(int i = 1 ;i<=pn;i++){
        for(int j = h ;j>=1;j--){
            if(proc[i]<=temp_hole2[j]){
                cout<<"P["<<i<<"] --> Hole["<<ind2[j]<<"]"<<endl;
                temp_hole2[j]=0;
                break;
            }
        }
    }

return 0;
}

