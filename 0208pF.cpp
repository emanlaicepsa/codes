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
vector<int> E[300005];
ll n;
ll mx[600005];
void mod(int x,int val){
	x+=n;
	mx[x] += val;
	for(x>>=1;x>=1 ;x>>=1){
		mx[x] = max(mx[x<<1],mx[x<<1|1]);
	}
}
int main(){
	IOS;
	cin>>n;
	memset(mx,-0x3f,sizeof(mx));
	for(int i=1;i<=n;i++){
		cin>>mx[n+i];
		mx[n+i] += 2;
	}
	for(int i=n;i>=1;i--){
		mx[i] = max(mx[i*2],mx[i*2+1]);
	}
	
	for(int i=1,a,b;i<n;i++){
		cin>>a>>b;
		E[a].pb(b);
		E[b].pb(a);
	}
	ll ans = 1e18;
	for(int i=1;i<=n;i++){
		mod(i,-2);
		for(auto &x:E[i]){
			mod(x,-1);
		}
		//cout<<mx[1]<<'\n';
		ans = min(ans,mx[1]);
		mod(i,2);
		for(auto &x:E[i]){
			mod(x,1);
		}
	}
	cout<<ans<<'\n';
}

