#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(k,n) for(int k=0;k<(n);k++)
#define rep1(k,n) for(int k=1;k<=(n);k++)
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll dp[105][105];
int main(){
	reset(dp,0x3f);
	rep(i,100)dp[i][i]=1,dp[i][1]=i,dp[1][i]=i;
	for(int i=2;i<=100;i++){
		for(int j=2;j<=100;j++){
			for(int k=1;k<i;k++)dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]);
			for(int k=1;k<j;k++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]);
		}
	}
	int n,m;
	cin>>n>>m;
	cout<<dp[n][m]<<'\n';
}

	





