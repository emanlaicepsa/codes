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
ll dp[105][3];
ll arr[105];
int main(){
	reset(dp,0x3f);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			if(arr[i]&(1<<j)){
				dp[i][j] = min({dp[i][j],dp[i-1][j^1],dp[i-1][2]});
			}
		}
		dp[i][2] = min({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) +1;
	}
	
	ll ans = min({dp[n][0],dp[n][1],dp[n][2]});
	cout<<ans<<'\n';
}

