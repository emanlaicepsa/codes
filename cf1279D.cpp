#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
vector<ll> item[2000005];
ll cnt[2000005];
const ll mod=998244353;

ll power(ll x,ll y){
	ll ans=1,mul=x;
	while(y){
		if(y&1)ans*=mul,ans%=mod;
		mul*=mul,mul%=mod;
		y>>=1;
	}
	return ans;
}

signed main(){
	ll n,k,tt;
	
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>tt;
			item[i].pb(tt);
			cnt[tt]++;
		}
	}
	
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll siz=item[i].size();
		ll res=0;
		for(auto j:item[i]){
			res+=cnt[j];
			res%=mod;
		}
		//cout<<res<<" "<<siz<<'\n';
		res*=power(siz,mod-2);
		res%=mod;
		ans+=res;
		ans%=mod;
	}
	
	ll x=(n*n)%mod;
	ans*=power(x,mod-2);
	// ans*=power(n*n,mod-2);
	ans%=mod;
	
	cout<<ans<<'\n';

}

