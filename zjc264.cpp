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

vector<pii> v;
ll dp[205][1005];
int main(){
	ll n,t,l,t1,t2;
	cin>>n>>t>>l;
	rep(i,n)cin>>t1>>t2, v.push_back({t1,t2});
	sort(all(v),[](pii a,pii b){
		return a.first>b.first;
	});
	for(auto item:v){
		for(int i=l;i>=1;i--){
			for(int j=t;j>=item.first*i;j--){
				dp[i][j]=max(dp[i][j],dp[i-1][j-item.first*i]+item.second);
				//cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
			}
		}
	}
	ll ans=0;
	rep1(i,l){
		ans=max(ans,dp[i][t]);
		//cout<<dp[i][t]<<'\n';
	}
	cout<<ans<<'\n';


}

