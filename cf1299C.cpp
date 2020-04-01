#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
deque<pii> dq;
pii operator -(pii a,pii b){
	return {a.fi-b.fi,a.se-b.se};
}
ll cross(pii a,pii b){
	return a.fi*b.se - a.se*b.fi;
}
ll arr[1000005];
int main(){
	IOS;
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		arr[i] += arr[i-1];
	}
	dq.pb({0,0});
	for(int i=1;i<=n;i++){
		pii x(arr[i],i);
		while(dq.size() >= 2 && cross(x - dq[dq.size()-1] ,dq[dq.size()-1]-dq[dq.size()-2] ) <= 0) dq.pop_back();
		dq.pb(x);
	}
	int l = 1, r;
	while(l<=n){
		while(dq[0].se <l) dq.pop_front();
		for(int i=l;i<=dq[0].se;i++){
			cout<<fixed<<setprecision(10)<<(dq[0].fi - arr[l-1])*1.0/ (dq[0].se - l+1)<<'\n';
		}
		l = dq[0].se +1; 
	}

}

