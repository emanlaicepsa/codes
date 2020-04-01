#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll dp[1005][5005];
ll arr[5005];
ll de[5005];
int n,k;

int main(){
	IOS
	while(cin>>n>>k){
		n++;
		memset(dp,0,sizeof(dp));
		memset(de,0,sizeof(de));
		memset(arr,0,sizeof(arr));
		for(int i=1;i<=k;i++){
			cin>>arr[i];
		}
		for(int i=2;i<=k;i++){
			de[i]=arr[i]-arr[i-1];
		}
		
		for(int i=1;i<=n;i++){
			dp[i][1]=(ll)1<<60;
			dp[i][0]=(ll)1<<60;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=2;j<=k;j++){
				dp[i][j]=min(dp[i][j-1],dp[i-1][j-2]+de[j]*de[j]);
			}
		}
		cout<<dp[n][k]<<'\n';
	}



}

