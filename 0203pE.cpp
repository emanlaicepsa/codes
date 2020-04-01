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
int arr[35];
ll n,m,t;
vector<ll> go(int l,int r){
	vector<ll> ans;
	for(int i=l;i<=r;i++){
		vector<ll> tmp;
		tmp.pb(arr[i]);
		for(auto x:ans){
			tmp.pb((x+arr[i])%m);
		}
		for(auto x:tmp) ans.pb(x);
		sort(all(ans));
		ans.resize(unique(all(ans))-ans.begin());
	}
	return ans;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i]; arr[i]%=m;
	}	
	if(n==1){
		cout<<arr[0]<<'\n';
		return 0;
	}
	vector<ll> v1 = go(0,n/2-1);
	vector<ll> v2 = go(n/2,n-1);
	ll ans = max(v1[v1.size()-1],v2[v2.size()-1]);
	for(auto i:v1){
		int p = upper_bound(all(v2),m-1-i) - v2.begin();
		ll x;
		if(p) {
			x = *(v2.begin()+p-1);
			ans = max(ans,x+i);
		}
		p = upper_bound(all(v2),m+m-1-i) - v2.begin();
		if(p) {
			x = *(v2.begin()+p-1);
			ans = max(ans,(x+i)%m);
		}
	}
	cout<<ans<<'\n';



}

