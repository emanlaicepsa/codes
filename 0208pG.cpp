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
ll dp[100005];
bool cmp(int a,int b){
	return a>b;
}
ll arr[100005];
int main(){
	IOS;
	ll a,b,h,w,n;
	cin>>a>>b>>h>>w>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1,cmp);
	dp[h] = 1;
	int ans = 10000000;
	if(a<=h&&b<=w)ans = 0;
	ll cur = 1;
	n = min(n,35LL);
	for(int i=1;i<=n;i++){
		cur *= arr[i];
		for(int j = a;j >= 1;j--){
			ll x = min(j * arr[i] , a);
			if(dp[j]) {
				if(!dp[x] || dp[x] > dp[j]* arr[i]) dp[x] = dp[j]* arr[i];
			}
		}
		if(dp[a] && w * (cur/ dp[a]) >= b ){
			ans = min(ans,i);
			break;
		}
	}
	swap(a,b);
	memset(dp,0,sizeof(dp));
	if(a<=h&&b<=w)ans = 0;
	dp[h] = 1;
	cur = 1;
	
	for(int i=1;i<=n;i++){
		cur *= arr[i];
		for(int j = a;j >= 1;j--){
			ll x = min(j * arr[i] , a);
			if(dp[j]) {
				if(!dp[x] || dp[x] > dp[j]* arr[i]) dp[x] = dp[j]* arr[i];
			}
		}
		if(dp[a] && w * (cur/ dp[a]) >= b ){
			ans = min(ans,i);
			break;
		}
	}
	
	if(ans > 10000)cout<<-1<<'\n';
	else cout<<ans<<'\n';

}

