#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
ll dp[105][2];
bool visited[105];
int n,k,d;
ll godp(int x){
	if(x<0) return 0;
	if(visited[x])return dp[x][1];
	ll ans=0;
	for(int i=1;i<=k&&i<=x;i++){
		if(i>=d){
			ans+=dp[x-i][0];
			//cout<<dp[x-1][0]<<'\n';
		}
		else ans+=godp(x-i);
		ans%=1000000007;
	}
	//cout<<x<<" "<<ans<<endl;
	visited[x]=1;
	return dp[x][1]=ans;
}


int main(){
	cin>>n>>k>>d;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=k;j>0;j--){
			if(i-j>=0)dp[i][0]+=dp[i-j][0];
			dp[i][0]%=1000000007; 
		}
	}
	ll a=godp(n);
	cout<<a<<endl;
}

