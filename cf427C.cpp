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
ll arr[100005];
vector<int> E1[100005];
vector<int> E2[100005];
vector<int> ord;
bool vis[100005];
ll cnt[100005];
ll co[100005];
const ll mod = 1000000007;
void dfs(int x){
	vis[x] = 1;
	for(auto &i:E1[x]){
		if(!vis[i])dfs(i);
	}
	ord.pb(x);
}
void dfs2(int x,int p){
	if(arr[x] < co[p]){
		cnt[p] = 1;
		co[p] = arr[x];
	}
	else if(arr[x] == co[p]){
		cnt[p] ++;
	}
	vis[x] = 1;
	for(auto &i:E2[x]){
		if(!vis[i])dfs2(i,p);
	}
}
int main(){
	IOS;
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	cin>>m;
	for(int i=0,a,b;i<m;i++){
		cin>>a>>b;
		E1[a].pb(b);
		E2[b].pb(a);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])dfs(i);
	} 
	memset(vis,0,sizeof(vis));
	reverse(all(ord));
	ll ans = 0;
	ll way = 1;
	for(auto j:ord){
		if(!vis[j]){
			co[j] = 1e18;
			dfs2(j,j);
			ans += co[j];
			way *= cnt[j];
			way %= mod; 
		}
	}
	cout<<ans<<" "<<way<<'\n';
}

