#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(n) for(int i=0;i<(n);i++)
#define rep1(n) for(int i=1;i<=(n);i++)
#define fi first
#define se second
#define reset(n) memset((n),0,sizeof(n))
#define all(n) n.begin(),n.end()

using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll arr[505];
ll dp[505][505];
int main(){
	
	int n;
	cin>>n;
	rep(n)cin>>arr[i];
	memset(dp,0x3f,sizeof(dp));
	rep(n)dp[i][i]=0;
	rep(n-1)dp[i][i+1]=0;
	for(int k=2;k<n;k++){
		for(int i=0;i+k<n;i++){
			for(int j=i+1;j<i+k;j++){
				dp[i][i+k]=min(dp[i][i+k],dp[i][j]+dp[j][i+k]+arr[i]*arr[j]*arr[i+k]);
			}
		}
	}
	cout<<dp[0][n-1]<<'\n';


}

