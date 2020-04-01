#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll arr[2000005];
ll sum[2000005];
ll lft;
ll n,k;
bool ok(ll x){
	for(int i=1;i<=n;i++){
		if(sum[i+x-1]-sum[i-1]>=lft)return 1;
	}
	return 0;
}
int main(){
	IOS
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		arr[n+i]=arr[i];
	}
	for(int i=1;i<=2*n;i++){
		sum[i]=sum[i-1]+arr[i];
	}
	ll tsum=sum[n];
	ll ans=n*(k/tsum);
	lft=k%tsum;
	ll l=0,r=n-1;
	while(l<r){
		ll m=(l+r)>>1;
		if(ok(m))r=m;
		else l=m+1;
	}
	ans+=l;
	cout<<ans<<'\n';
}

