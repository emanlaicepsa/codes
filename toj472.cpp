#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#pragma GCC optimize ("O3")
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll bit[1000005][2];
ll n,t,tans,ans;
inline void add(int id,int pos,int val){
	for(int i=pos;i<=n;i+=(i&-i))bit[i][id]+=val;
}
inline ll que(int id,int pos){
	ll ans = 0;
	for(int i=pos;i;i-=(i&-i))ans += bit[i][id];
	return ans;
}
int main(){
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t;
		tans = que(0,t-1);
		add(0,t,1);
		ans += que(1,t-1);
		add(1,t,tans);
	}
	cout<<ans<<'\n';
}

