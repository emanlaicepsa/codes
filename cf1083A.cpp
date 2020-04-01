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
ll gas[300005];
vector<pii> E[300005];
ll dp[300005];
ll ans = 0;
void dfs(int x,int pa){
	ll m1 = 0;
	ll m2 = 0;
	for(auto i:E[x]){
		if(i.fi == pa)continue;
		dfs(i.fi,x);
		if(dp[i.fi] - i.se >= m1){
			m2 = m1;
			m1 = dp[i.fi] - i.se;
		}
		else if(dp[i.fi] - i.se > m2){
			m2 = dp[i.fi] - i.se;
		}
	}
	dp[x] = max(dp[x] , m1 + gas[x]);
	ans = max({ans,dp[x],m1+m2+gas[x]});
}
int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>gas[i];
	}
	for(int i=1,a,b,v;i<=n-1;i++){
		cin>>a>>b>>v;
		E[a].pb({b,v});
		E[b].pb({a,v});
	}
	dfs(1,0);
	/*for(int i=1;i<=n;i++){
		cout<<dp[i]<<'\n';
	}*/
	cout<<ans<<'\n';
}

