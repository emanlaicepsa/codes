#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
int arr[100005];
int arr2[100005];
int dp[100005][4];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	} 
	arr2[1]=0;
	dp[1][0]=1;
	dp[1][1]=1;
	dp[1][3]=1;
	int ans=1;
	for(int i=2;i<=n;i++){
		arr2[i]=arr[i-1]+1;
		dp[i][1]=1+dp[i-1][0];
		if(arr[i]>arr[i-1]){
			dp[i][0]=dp[i-1][0]+1;
			dp[i][2]=dp[i-1][2]+1;
			dp[i][3]=dp[i-1][3]+1;
		}
		else{
			dp[i][0]=1;
			dp[i][3]=2;
		}
		if(arr[i]>arr2[i-1]){
			dp[i][2]=max(dp[i][2],1+dp[i-1][1]);
		}
		ans=max({ans,dp[i][0],dp[i][1],dp[i][2],dp[i][3]});
	}
	cout<<ans<<'\n';
}

