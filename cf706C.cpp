#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
ll cost[100005]; 
ll dp[100005][2];
string arr[100005];
int main(){
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cost[i];
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	
	dp[n][0]=0;
	dp[n][1]=cost[n];
	for(int i=n-1;i>=1;i--){
		
		dp[i][0]=(ll)1<<60;
		dp[i][1]=(ll)1<<60;
		string re1=arr[i];
		string re2=arr[i+1];
		reverse(re1.begin(),re1.end());
		reverse(re2.begin(),re2.end());
		//cout<<re1<<endl<<re2<<endl;
		if(arr[i]<=arr[i+1])dp[i][0]=min(dp[i][0],dp[i+1][0]);
		
		if(arr[i]<=re2)dp[i][0]=min(dp[i][0],dp[i+1][1]);
		
		if(re1<=arr[i+1])dp[i][1]=min(dp[i][1],cost[i]+dp[i+1][0]);
		
		if(re1<=re2)dp[i][1]=min(dp[i][1],cost[i]+dp[i+1][1]);
		
		//cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	if(dp[1][0]==(ll)1<<60&&dp[1][1]==(ll)1<<60){
		cout<<-1<<'\n';
	}
	else {
		ll ans=min(dp[1][0],dp[1][1]);
		cout<<ans<<'\n';
	}
}

