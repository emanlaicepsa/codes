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
ll deg[5005];
vector<int> E[5005];
bool vis[5005];
int n,m; 
int cnt;
void dfs(int x){
	vis[x] = 1;
	if(deg[x]&1)cnt++;
	for(auto i:E[x]){
		if(!vis[i])dfs(i);
	}
}
int main(){
	IOS;
	cin>>n>>m;
	
	for(int i=0,a,b;i<m;i++){
		cin>>a>>b;
		deg[a] ++;
		deg[b] ++;
		E[a].pb(b);
		E[b].pb(a);
	}
	
	ll ans;
	bool ok = 1;
	dfs(0);
	for(int i=0;i<n;i++){
		if(!vis[i] || (deg[i]&1) ) ok = 0;
	}
	if(ok){
		cout<<0<<'\n';
		return 0;
	}
	ans = cnt?cnt:2;
	for(int i=1;i<n;i++){
		if(!vis[i]){
			cnt=0,dfs(i);
			ans += cnt?cnt:2;
		}
			//cout<<cnt<<'\n';
	}
	cout<<ans/2<<'\n';

}

