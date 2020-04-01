#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
struct item{
	ll w,m,c;
};
ll dp[1000005];
vector<item> v;
deque<pii> mono;
int main(){
	IOS;
	ll n,w,m,c,t;
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i].w>>v[i].m>>v[i].c;
	}
	cin>>t;
	ll ans = 0;
	for(int i=0;i<n;i++){
		int now = i&1;
		for(int j=0;j<v[i].w;j++){
			mono.clear();
			for(int k=j;k<=t;k+=v[i].w){
				while(!mono.empty()&&(k-mono.front().se)/v[i].w > v[i].c) mono.pop_front();
				while(!mono.empty() && dp[k] - k/v[i].w*v[i].m >= mono.back().fi)mono.pop_back(); 
				mono.pb({dp[k] - k / v[i].w * v[i].m ,k});
				dp[k] = max(dp[k],k / v[i].w * v[i].m + mono.front().fi);
				ans = max(ans,dp[k]);
 			}
		}
	}
	cout<<ans<<'\n';

}

