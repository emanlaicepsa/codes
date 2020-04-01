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
ll dp[30005][805];
ll cnt[30005];
map<pii,int> m;

int dfs(int x,int d){
	//cout<<x<<" "<<d<<'\n';
	if(x>30000)return 0;
	if(m.find({x,d})!=m.end())return m[{x,d}];
	return m[{x,d}] = cnt[x] + max({dfs(x+d,d),dfs(x+d-1,d-1),dfs(x+d+1,d+1)});
}

int main(){
	IOS;
	int n,d;
	cin>>n>>d;
	for(int i=1,a;i<=n;i++){
		cin>>a;
		cnt[a] ++;
	}
	
	
	if(d>=700){
		cout<<dfs(d,d)<<'\n';
	}
	
	else{
		cnt[d] ++;
		ll ans = 0;
		dp[d][d] = cnt[d];
		for(int i=d+1;i<=30000;i++){
			for(int j=1;j<=min(i,800);j++){
				ll x = max({dp[i-j][j],dp[i-j][j+1],dp[i-j][j-1]});
				if(x>0){
					dp[i][j] = cnt[i] + x;
					ans = max(ans,dp[i][j]);
				}
				//cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
			}
		}
		cout<<ans-1<<'\n';
	}


}

