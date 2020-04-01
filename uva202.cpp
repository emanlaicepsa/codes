#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#include<memory.h>
using namespace std;
int used[30005];
int main(){
	int a,b;
	while(cin>>a>>b){
		memset(used,0,sizeof(used));
		int len=0;
		int t=a/b;
	cout<<a<<"/"<<b<<" = "<<t<<".";
	a%=b;
	string ans="0";
	bool go = true;
	int count=1;
	int key=1;
	while(1){
		a*=10;
		if(used[a]){
			key=used[a];
			len=count-key;
			break;
		}
		used[a]=count;
		ans.push_back(a/b+'0');
		a%=b;
		count++;
	}	
	for(int z=1;z<ans.length();z++){
		if(z==51)break;
		if(z==key)cout<<"(";
		cout<<ans[z];
	}
	if(ans.length()>=51)cout<<"...";
	cout<<")"<<endl;
	cout<<"   "<<len<<" = number of digits in repeating cycle"<<endl<<endl;
		
	}
	

}

