#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int count=0;
	string a,b;
	while(T--){
		count++;
		cin>>a;
		b=a;
		for(int x=0;x<a.length();x++){
			if(a[x]=='4'){
				a[x]--;
				b[x]='1';
			}
			else b[x]='0';
		}
		cout<<"Case #"<<count<<": ";
		for(int x=0;x<a.length();x++)cout<<a[x];
		cout<<" ";
		int flag=0;
		for(int x=0;x<a.length();x++){
			if(b[x]=='0'&&flag==0)continue;
			else{
				cout<<b[x];
				flag=1;
			}
		}
		cout<<endl;
	}
 







}

