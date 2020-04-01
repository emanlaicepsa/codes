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
ll cur[15];
ll arr[300005];
int main(){
	IOS;
	ll n,m,k;
	cin>>n>>m>>k;
	memset(cur,0x3f,sizeof(cur));
	cur[0] = k;
	ll ans = 0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		arr[i] += arr[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			ans = max(ans,arr[i] - cur[j]);
		}
		cur[i%m] += k;
		cur[i%m] = min(cur[i%m],arr[i]+k);
	}
	cout<<ans<<'\n';

}

