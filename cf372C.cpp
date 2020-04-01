#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
struct fire{
	ll pos;
	ll val;
	ll t;
}; 
vector<fire> v;
ll dp[2][150005];
deque<pii> deq;
int main(){
	IOS;
	ll n,m,d;
	cin>>n>>m>>d;
	v.resize(m+1);
	for(int i=0;i<m;i++){
		cin>>v[i].pos>>v[i].val>>v[i].t;
	}
	for(int i=1;i<=n;i++){
		dp[0][i] = v[0].val - abs(v[0].pos - i);
	}
	for(ll i=1;i<=m;i++){
		int cur = i&1;
		deq.clear();
		ll dt = v[i].t - v[i-1].t;
		int now = 1;
		for(ll j=1;j<=n;j++){
			while(!deq.empty() && deq.front().se < j - dt * d) deq.pop_front();
			while(now<=n && now <= j + dt * d){
				while(!deq.empty() && dp[cur^1][now] > deq.back().fi){
					deq.pop_back();
				}
				deq.pb({dp[cur^1][now],now});
				now++;
			}
			dp[cur][j] = deq.front().fi + v[i].val - abs(v[i].pos - j);
		}
	}
	ll ans = -1e16;
	for(int i=1;i<=n;i++){
		ans = max(ans,dp[m&1^1][i]);
	}
	cout<<ans<<'\n';

}

