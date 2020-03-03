#include<bits/stdc++.h>
#define MaxIn 100
using namespace std;
void safety_algo(int n,int m ,int allocation[MaxIn][MaxIn],int Need[MaxIn][MaxIn],int Avilable[MaxIn]);

int main(){

    int n,m;
    int allocation[MaxIn][MaxIn],Max[MaxIn][MaxIn], Avilable[MaxIn],Instances[MaxIn],Need[MaxIn][MaxIn];

    freopen("bank.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>Instances[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>allocation[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            Avilable[i]=Avilable[i]+allocation[j][i];
        }
    }
    for(int i=0;i<m;i++){
        Avilable[i]=Instances[i]-Avilable[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Max[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Need[i][j]=Max[i][j]-allocation[i][j];
        }
    }

    safety_algo(n,m,allocation,Need,Avilable);



return 0;
}

void safety_algo(int n,int m ,int allocation[MaxIn][MaxIn],int Need[MaxIn][MaxIn],int Avilable[MaxIn]){
    int Count=0,ind=0;
    int Finish[MaxIn],Ans[MaxIn];

    for(int i=0;i<n;i++){
       Finish[i]=false;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(Finish[i]==false){
                    int flag=0;
               for(int j=0;j<m;j++){
                    if(Need[i][j]>Avilable[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                   for(int k=0;k<m;k++){
                        Avilable[k]=Avilable[k]+allocation[i][k];
                   }
                   Finish[i]=true;
                    Count++;
                    Ans[ind++]=i;
                }

            }

        }
    }
    int i;
    cout<<"Safe sequence :";
        if(Count==n){
            for(i=0;i<n-1;i++)
                cout<<"P"<<Ans[i]<<"-> ";
                cout<<"P"<<Ans[i];
        }
        else{
            cout<<"The sequence is not safe ";
        }

}
