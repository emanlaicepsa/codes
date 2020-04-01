#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(k,n) for(int k=0;k<(n);k++)
#define rep1(k,n) for(int k=1;k<=(n);k++)
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()

using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll dp[105][105];
ll arr[105]; 
int main(){
	int n;
	while(cin>>n){
		reset(arr,0);
		reset(dp,0);
		rep1(i,n)cin>>arr[i];
		rep1(i,n)dp[i][i]=arr[i];
		rep1(i,n-1)dp[i][i+1]=dp[i][i]+dp[i+1][i+1];
		for(int k=2;k<n;k++){
			for(int i=1;i+k<=n;i++){
				for(int j=i;j<i+k;j++){
					ll res;
					if((k+1)&1)res=dp[i][j]*dp[j+1][i+k];
					else res=dp[i][j]+dp[j+1][i+k];
					dp[i][i+k]=max(dp[i][i+k],res);
				}
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
			}
		}*/
		cout<<dp[1][n]<<'\n';
	}



}
