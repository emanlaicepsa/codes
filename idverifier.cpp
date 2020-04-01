#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#include <assert.h>
using namespace std;

int main(){

string a;
while(cin>>a){
	int sum=0;
	if(a[0]>='A'&&a[0]<='H'){
		sum+=a[0]-'A'+10;
	}
	if(a[0]>='J'&&a[0]<='N'){
		sum+=a[0]-'J'+18;
	}
	if(a[0]>='P'&&a[0]<='V'){
		sum+=a[0]-'P'+23;
	}
	if(a[0]=='X'){
		sum+=30;
	}
	if(a[0]=='Y'){
		sum+=31;
	}
	if(a[0]=='W'){
		sum+=32;
	}
	if(a[0]=='Z'){
		sum+=33;
	}
	if(a[0]=='I'){
		sum+=34;
	}
	if(a[0]=='O'){
		sum+=35;
	}
	sum=(sum%10)*9+sum/10;
	
	for(int x=1;x<=8;x++){
		//cout<<sum<<endl;
		sum+=(a[x]-'0')*(9-x);
	}
	//cout<<sum<<endl;
	sum+=a[9]-'0';
	assert(sum%10==0);
	
}



}

