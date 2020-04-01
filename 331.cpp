#include<iostream>
using namespace std;

int main()
{	
    long long azero=0,bzero=0;
    long long count=0;
	string a,b;
	cin>>a>>b;
	for(int c=0;c<a.size();c++){
		if(a[c]=='0'){
			azero++;
		}
	}
	for(int c=0;c<b.size();c++){
		if(b[c]=='0'){
			bzero++;
		}
	}
	count=((a.size()-azero)*(b.size()-bzero));
	cout<<count<<endl;





}

