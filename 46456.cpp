#include<iostream>
#include<algorithm>
using namespace std;
int elec[1000];
int plug[1000];
int compare[1000][1000];
int main()
{
	int t,a,b,time;
	cin>>t;
	for(int f=1;f<=t;f++){
		cin>>a>>b;
		for(int c=0;c<a;c++){
			cin>>elec[c];
		}
		for(int c=0;c<a;c++){
			cin>>plug[c];
			for(int d=0;d<a;d++){
			compare[c][d]=plug[c]^elec[d];}
		}
		{sort(compare,compare+(a*a)); }
		for(int c=0;c<a;c++){
			int w=compare[0][c];
			for(int d=1;d<a;d++){
				
			}
		
		}
		if(time==-1){
			cout<<"Case #"<<f<<": "<<"IMPOSSIBLE"<<endl;
		}
		else{
			cout<<"Case #"<<f<<": "<<time<<endl;
		}
	} 







}

