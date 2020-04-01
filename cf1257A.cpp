#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int main(){
	int t,n,s,a,b;
	cin>>t;
	while(t--){
		cin>>n>>s>>a>>b;
		if(a>b)swap(a,b);
		int ans=min(b-a+s,n-1);
		cout<<ans<<'\n';
	}



}

