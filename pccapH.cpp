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
vector<ll> v;
signed main(){
	int n,cnt = 0;
	cin>>n;
	ll ans = 1e18+5;
	for(ll i=0,x;i<n;i++){
		cin>>x;
		if(!(x&1)){
			cnt++;
			ans = min(ans,x);
			v.pb(x);
		}
	}
	sort(all(v));
	if(v.size() <=1){
		cout<<"NO\n";
	}
	else if(cnt&&!(cnt&1)){
		cout<<"YES\n";
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" \n"[i==v.size()-1];
		}
	}
	else {
		cout<<"OuO\n";
		cout<<ans<<'\n';
	}

}

