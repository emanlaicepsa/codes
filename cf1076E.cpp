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
ll add[300005];
int dep[300005];
ll ans[300005];
vector<pii> que[300005];
int n;
vector<int> E[300005];
ll cur = 0;
void dfs(int x,int p){
	dep[x] = dep[p] + 1;
	for(auto i:que[x]){
		add[dep[x]] += i.fi;
		add[min(dep[x] + i.se + 1, n+1)] -= i.fi;
	}
	cur += add[dep[x]];
	ans[x] = cur;
	for(auto i:E[x]){
		if(i==p)continue;
		dfs(i,x);
	}
	cur -= add[dep[x]];
	for(auto i:que[x]){
		add[dep[x]] -= i.fi;
		add[min(dep[x] + i.se + 1, n+1)] += i.fi;
	}
}
int main(){
	IOS;
	cin>>n;
	for(int i=0,a,b;i<n-1;i++){
		cin>>a>>b;
		E[a].pb(b);
		E[b].pb(a);
	}
	int q,a,b,c;
	cin>>q;
	while(q--){
		cin>>a>>b>>c;
		que[a].pb({c,b});
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" \n"[i==n];
	}

}

