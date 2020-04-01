#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int main(){
	ll t,a,b,n,s;
	cin>>t;
	while(t--){
		cin>>a>>b>>n>>s;
		if(a*n+b<s)cout<<"No\n";
		else if(b<s%n)cout<<"No\n";
		else cout<<"Yes\n";
	} 



}

