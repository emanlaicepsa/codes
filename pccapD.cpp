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
ll dp[100005][200];
const ll mod = 998244353;
int main(){
	for(int i=1;i<=200;i++)dp[1][i] = 1;
	for(int i=2;i<=100000;i++){
		ll sum = 0;
		for(int j=1;j<=200;j++){
			sum += dp[i-1][j];
			sum%=mod;
			dp[i][j] = sum;
		}
	}
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		dp[i][1]=1;
		for(int j=2;j<=m;j++){
			dp[i][j] += dp[i][j-1];
			dp[i][j] %= mod;
		}
	}
	
	/*for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
		}
	}*/
	ll ans = 0;
	for(int j=m;j>1;j--){
		for(int i=1;i<n-1;i++){
			//cout<<i<<" "<<j-1<<" "<<n-i-1<<" "<<j-1<<" "<<(dp[i][j-1] * dp[n-i-1][j-1] )<<"\n";
			ans += (dp[i][j-1] * dp[n-i-1][j-1] )%mod;
			ans %=mod;
		}
	}
	
	cout<<ans<<'\n';


}

