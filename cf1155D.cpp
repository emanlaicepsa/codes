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
ll arr[300005][3];
ll dp[300005][3];
int main(){
	IOS;
	ll n,a;
	cin>>n>>a;
	for(int i=1;i<=n;i++){
		cin>>arr[i][0];
		arr[i][1] = arr[i][0]*a;
		arr[i][2] = arr[i][0];
	};
	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<=j;k++){
				dp[i][j] = max(dp[i][j], dp[i-1][k] + arr[i][j]);
			}
			ans = max(ans,dp[i][j]);
		}
	}
	cout<<ans<<'\n';

}

