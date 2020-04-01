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
ll arr[200005];
ll n,k;

ll check(ll x){
	v.clear();
	v.pb(arr[1]);
	ll ans=0;
	for(int i=2;i<=n;i++){
		if(arr[i]>0){	
			if(v[0]*arr[i] < x) {
				ll l = 0,r = v.size()-1;
				while(l<r){
					int m = (l+r+1)>>1;
					if(v[m]*arr[i] >= x){
						r=m-1;
					}	
					else{
						l=m;
					}
				} 
				//cout<<arr[i]<<" "<<l<<'\n';
				ans += l+1;
			}	
		}
		else{
			if(v[v.size()-1]*arr[i]<x) {
				ll l = 0,r = v.size()-1;
				while(l<r){
					int m = (l+r)>>1;
					if(v[m]*arr[i] >= x){
						l=m+1;
					}	
					else{
						r=m;
					}
				} 
				//cout<<arr[i]<<" "<<v.size()-l<<'\n';
				ans += v.size()-l;
			}	
		}
		v.pb(arr[i]);
	}
	//cout<<x<<" "<<ans<<'\n';
	return ans;
}
int main(){
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+n+1);
	ll l = -1e18, r = 1e18;
	while(l<r){
		ll m = (l+r+1)>>1;
		if(check(m)<k) l=m;
		else r=m-1;
	}
	cout<<l<<'\n';

}

