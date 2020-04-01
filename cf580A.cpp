#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
ll dp[100005];
ll cnt[100005];
int n;


int main(){
	IOS
	cin>>n;
	int temp;
	for(int i=0;i<n;i++)cin>>temp,cnt[temp]++;
	dp[1]=1*cnt[1];
	dp[2]=max(dp[1],2*cnt[2]);
	for(int i=3;i<=100000;i++){
		dp[i]=max(dp[i-1],i*cnt[i]+dp[i-2]);
	}
	cout<<dp[100000]<<'\n';


}

