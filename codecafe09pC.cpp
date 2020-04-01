#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int main(){
	int t;
	cin>>t;
	int a;
	while(t--){
		cin>>a;
		if(a>=3||a==0)cout<<-1<<'\n';
		else if(a==1)cout<<1<<" "<<2<<" "<<3<<'\n';
		else cout<<3<<" "<<4<<" "<<5<<'\n';
	}



}

