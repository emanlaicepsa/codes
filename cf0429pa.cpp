#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_wiith_stdio(false);cin.tie(0);
using namespace std;

int main(){
	int buy=100000;
	int sell=0;
	int n,m,r;
	cin>>n>>m>>r;
	int T;
	for(int x=0;x<n;x++){
		cin>>T;
		if(T<buy)buy=T;
	}
	for(int x=0;x<m;x++){
		cin>>T;
		if(T>sell)sell=T;
	}
	if(sell-buy<=0)cout<<r<<endl;
	else{
		cout<<r+(r/buy)*(sell-buy)<<endl;
	}


}

