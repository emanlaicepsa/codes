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
vector<ll> v;
ll n,k,a,b;
ll ans(ll l,ll r){
	//cout<<l<<" "<<r<<'\n';
	ll qq = upper_bound(all(v),r) - lower_bound(all(v),l);
	if(qq == 0){
		return a;
	}
	if(l==r){
		return b*qq;
	}
	ll len = r-l+1;
	ll m = (l+r)>>1;
	long double x = len * 1.0 * b * qq;
	if(x > 1e18)return ans(l,m)+ans(m+1,r);
	return min( len * b * qq , ans(l,m)+ans(m+1,r) ); 
}


int main(){
	IOS;
	cin>>n>>k>>a>>b;
	for(ll i=1,x;i<=k;i++){
		cin>>x;
		v.pb(x);
	} 
	sort(all(v));
	cout<<ans(1,1LL<<n)<<'\n';
}

