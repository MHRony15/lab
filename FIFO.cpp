#include<bits/stdc++.h>
using namespace std;
int main(){
 int rs,ref_str[100],fs,memo[100],pf=1,m=1;
 cout<<"Enter the number of reference string: ";
 cin>>rs;
 cout<<"Enter the reference string: ";
 for(int i=0;i<rs;i++){
    cin>>ref_str[i];
 }
 cout<<"Enter the number of Frame in memory: ";
    cin>>fs;
    memo[0]=ref_str[0];
    for(int i=1;i<rs;i++){
        int flag=0;
        for(int j = 0;j<fs;j++){
            if(memo[j]==ref_str[i])
                flag=1;
        }
        if(flag==0){
            pf++;
            if(m==fs){
                m=0;
            }
           memo[m]=ref_str[i];
           m++;
        }
    }
    cout<<"Page fault :"<<pf;
return 0;
}
