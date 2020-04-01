#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define int ll
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int idx = 0;
unordered_map<ll,ll> f;
ll cal(ll n){
	if(f[n]) return f[n];
	if(n==1||n==0)return 1;
	return f[n] = 2*cal(n/2) + 1;
}
ll solve(ll n,ll l,ll r){
//	cout<<n<<" "<<idx<<'\n';
	ll x = cal(n);
	if(idx + x < l){
		idx += x;
		return 0; 
	}
	if(idx>=r){
		return 0;
	}
	if(n==0){
		idx ++;
		return 0;
	}
	if(n==1){
		idx ++;
		if(idx>=l&&idx<=r)return 1;
	}
	ll ta = 0;
	ta += solve(n/2,l,r);
	idx ++;
	if(idx>=l&&idx <= r) ta += (n&1);
	ta += solve(n/2,l,r);
	//cout<<n<<" "<<idx<<" "<<ta<<'\n';
	return ta;
}

signed main(){
	ll n,a,b; 
	cin>>n>>a>>b;
	cout<<solve(n,a,b)<<'\n';
}

