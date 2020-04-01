#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;
int main()
{
	int a[4];
	srand(time(NULL));
	int have[11]={0};
	have[10]=1;
	for (int b=0;b<4;b++){
		int c=10;
		while(have[c]){
		  c=rand()%10;}
		  a[b]=c;
		have[a[b]]=true;
	}
	for(int b=0;b<4;b++){
		cout<<a[b];
	}
	cout<<endl;
	char d[4];
	while(cin>>d){
		bool repeat=false;
		for(int b=0;b<3;b++){
			for(int e=b+1;e<4;e++){
				if(d[b]==d[e]){
					cout<<"數字不能重複"<<endl; 
					repeat=true;
					break;
				}
			}
		}
		if(repeat==true){
			continue;
		}
		int atime=0,btime=0;
		for(int b=0;b<4;b++){
			for(int e=0;e<4;e++)
				if((d[b]-'0')==a[e]){
					if(b==e){atime++;}
					else{btime++;}
				}
		}
		cout<<atime<<"A"<<btime<<"B"<<endl;
	}





}

