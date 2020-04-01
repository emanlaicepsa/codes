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
ll arr[55];
ll dp[55][55];
int main(){
	ll L,N;
	while(cin>>L){
		if(L==0)break;
		cin>>N;
		reset(arr);
		memset(dp,0x3f,sizeof(dp));
		arr[0]=0;
		arr[N+1]=L;
		rep1(N)cin>>arr[i];
		rep(N+2)dp[i][i]=0;
		rep(N+1)dp[i][i+1]=0;
		
		for(int k=2;k<N+2;k++){
			for(int i=0;i+k<N+2;i++){
				for(int j=i+1;j<i+k;j++){
					dp[i][i+k]=min(dp[i][i+k],dp[i][j]+dp[j][i+k]+arr[i+k]-arr[i]);
				}
			}
		}
		
		cout<<"The minimum cutting is "<<dp[0][N+1]<<".\n";
	}



}

