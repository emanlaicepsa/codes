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
ll n,m;
ll arr[100005];
ll pos[100005];
bool ok(ll x){
	ll nx = 0 ,nid = 1;
	for(int i=1;i<=n;i++){
		nx = arr[i];
		ll to;
		if(nx <= pos[nid])to = nx + x;
		else{
			if(nx - pos[nid] > x) return 0;
			ll tmp = nx - pos[nid];
			to = nx + max(x-2*tmp,(x-tmp)/2);
		}
		while(nid<=m && pos[nid]<=to) nid++;
		if(nid>m)break;
	}
	return nid>m;
}
int main(){
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=m;i++){
		cin>>pos[i];
	}
	ll l = 0 , r = 1e11;
	while(l<r){
		ll m = (l+r)>>1;
		if(ok(m)) r=m;
		else l=m+1;
	} 
	cout<<l<<'\n';
}

