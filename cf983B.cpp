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
ll dp[5005][5005];

int main(){
	IOS;
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>dp[i][i];
	}
	for(int l=2;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			dp[i][i+l-1] = dp[i][i+l-2]^dp[i+1][i+l-1];
		}
	}
	for(int l=2;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			dp[i][i+l-1] = max({dp[i][i+l-1],dp[i][i+l-2],dp[i+1][i+l-1]});
		}
	}
	int q,l,r;
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<dp[l][r]<<'\n';
	}

}

