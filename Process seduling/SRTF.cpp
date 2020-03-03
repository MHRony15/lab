#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct proc
{
	int AT,BT,CT,TaT,WT,TBT;
	string pro_id;
}Schedule;

bool comp(Schedule a,Schedule b)
{
	return a.AT<b.AT;
}
bool comp2(Schedule a,Schedule b)
{
	return a.BT<b.BT;
}

int main()
{
	Schedule pro[10];
	int n,i,j,complite_proc=0,current_time=0;

	cout<<"Enter the number of Process::";
	cin>>n;

	cout<<"Enter the Process id arrival time burst time :::";

	for(i=0;i<n;i++)
	{
		cin>>pro[i].pro_id;
		cin>>pro[i].AT;
		cin>>pro[i].BT;
		pro[i].TBT=pro[i].BT;
	}

	sort(pro,pro+n,comp);

	while(complite_proc<n)
	{
		for(j=0;j<n;j++)
		{

			if(pro[j].AT>current_time)
			break;
		}

		sort(pro,pro+j,comp2);
		if(j>0)
		{

			for(j=0;j<n;j++)

			{
				if(pro[j].BT!=0)
				break;
			}

			if(pro[j].AT>current_time)

			{
				current_time=pro[j].AT;

			}
			pro[j].CT=current_time+1;
			pro[j].BT--;
		}
		current_time++;
		complite_proc=0;
		for(j=0;j<n;j++)
		{
			if(pro[j].BT==0)
			complite_proc++;
		}
	}
	double awt;

	cout<<"ProID\tArrival time\tBurst time\tCompletion time\tTurnaround time\tWaiting time\n";

	for(i=0;i<n;i++)
	{
		pro[i].TaT=pro[i].CT-pro[i].AT;
		pro[i].WT=pro[i].TaT-pro[i].TBT;

        awt=awt+pro[i].WT;

		cout<<pro[i].pro_id<<"\t\t"<<pro[i].AT<<"\t\t"<<pro[i].TBT<<"\t\t"<<pro[i].CT<<"\t\t"<<pro[i].TaT<<"\t\t"<<pro[i].WT;
		cout<<endl;
	}
	cout<<" AVERAGE WAITING TIME: "<<awt/n<<endl;
	return 0;
}
