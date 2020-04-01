#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define mod 1000000007 
using namespace std;
using ll= long long;
ll dp[100005][2];
ll ans[100005];
ll sum[100005];
ll cursum;
int main(){
	int t,k;
	cin>>t>>k;
	for(int i=0;i<=100000;i++){
		dp[i][0]=1;
		if(i-k>=0){
			dp[i][1]+=dp[i-k][1];
			dp[i][1]+=dp[i-k][0];
			dp[i][1]%=mod;
		}
		dp[i][0]+=cursum;
		dp[i][0]%=mod;
		
		cursum+=dp[i][1];
		cursum%=mod;
		ans[i]=dp[i][0]+dp[i][1];
		ans[i]%=mod;
		if(i){
			sum[i]=sum[i-1]+ans[i];
			sum[i]%=mod;
		}
	}
	
	int a,b;
	while(t--){
		cin>>a>>b;
		ll an=sum[b]-sum[a-1];
		if(an<0)an+=mod;
		cout<<an<<'\n';
	}

}

