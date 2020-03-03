#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,Hole[100],p,ind[100],in=0;
    cout<<"Enter the number of hole: ";
    cin>>h;
    cout<<"Enter the Hole size of :\n";
    for(int i=1;i<=h;i++){
        cout<<"h"<<i<<": ";
        cin>>Hole[i];
        ind[i]=i;
    }
    cout<<"Enter the Process Size:";
    cin>>p;
    for(int i=1;i<=h;i++){
        if(p<=Hole[i]){
           cout<<"First Fit Hole: h"<<i;
           break;
        }


    }
    for(int i=1;i<=h;i++){
            for(int j=i;j<=h;j++){
                if(Hole[i]>Hole[j]){
                    swap(Hole[i],Hole[j]);
                    swap(ind[i],ind[j]);
                }
            }
    }
    for(int i=1;i<=h;i++){
        if(p<=Hole[i]){
          cout<<"\nBest Fit Hole: h"<<ind[i];
          break;
        }
    }
    for(int i=h;i>=1;i++){
        if(p<=Hole[i]){
          cout<<"\nWorst Fit Hole: h"<<ind[i];
          break;
        }
    }


return 0;
}
