#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll n,k;
bool ok(ll x){
	ll tmp = n/x;
	//cout<<x<<" "<<tmp<<" "<<k<<'\n';
	if(tmp<(k*(k+1)/2)){
		return 0;
	}
	return 1;
}
vector<ll> di;
int main(){	
	cin>>n>>k;
	if(k>1000000){
		cout<<-1<<'\n';
		return 0;
	}
	if(n<(k*(k+1)/2)){
		cout<<-1<<'\n';
		return 0;
	}
	for(ll i=1;i*i<=n;i++){
		if(!(n%i)) {
			di.pb(i);
			if(i*i!=n)di.pb(n/i);
		} 
	}
	sort(di.begin(),di.end());
	//for(auto i:di)cout<<i<<'\n';
	int l = 0,r = di.size()-1;
	while(l<r){
		int m = (l+r+1)>>1;
		if(ok(di[m]))l=m;
		else r=m-1;
	}
	ll res = n/di[l];
	for(int i=1;i<=k-1;i++){
		cout<<di[l]*i<<" ";
		res -= i;
	}
	cout<<di[l]*res<<'\n';
}

