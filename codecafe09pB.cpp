#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll ans[10005];
ll dp[10005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ll a=0;
		ll sum=0;
		ll t;
		for(int j=1;j<=m;j++){
			cin>>t;
			sum=max(sum+t,(ll)0);
			a=max(a,sum);
		}
		ans[i]=a;
	}
	dp[1]=ans[1];
	for(int i=2;i<=n;i++){
		dp[i]=max(dp[i-1],dp[i-2]+ans[i]);
	}
	cout<<dp[n]<<'\n';



}

