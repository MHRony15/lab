#include<bits/stdc++.h>
#include<queue>
using namespace std;
queue<int>myq;
queue<int>myq2;
int main(){
 int rs,ref_str[100],fs,memo[100],pf=0,m=0,temp,change,pop;
 cout<<"Enter the number of reference string: ";
 cin>>rs;
 cout<<"Enter the reference string: ";
 for(int i=0;i<rs;i++){
    cin>>ref_str[i];
 }
 cout<<"Enter the number of Frame in memory: ";
    cin>>fs;
    for(int k=0;k<fs;k++){
        myq.push(k);
        memo[k]=-1;
    }
    for(int i=0;i<rs;i++){
        int flag=0;
        for(int j = 0;j<fs;j++){

            if(memo[j]==ref_str[i]){
                flag=1;
                pop=j;
            }
        }
        if(flag==1){
            for(int i=0;i<fs;i++){

                    temp=myq.front();
                    if(temp==pop){
                        change=temp;
                        myq.pop();
                    }
                    else{
                        myq2.push(temp);
                        myq.pop();
                    }
            }
            for(int i =0;i<fs-1;i++){
                temp=myq2.front();
                myq2.pop();
                myq.push(temp);
            }
            myq.push(change);

        }
        else{
                pf++;
                m=myq.front();
                memo[m]=ref_str[i];
                myq.pop();
                myq.push(m);
            }
            for(int j = 0;j<fs;j++){
                cout<<memo[j]<<" ";
            }
            if(flag==0){
                cout<<" -->Page Fault";
            }
            cout<<endl;
    }

    cout<<"Page fault :"<<pf;
return 0;
}
