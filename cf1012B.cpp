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
vector<int> E[400005];
bool vis[400005];
void dfs(int x){
	vis[x] = 1;
	for(auto i:E[x]){
		if(!vis[i])dfs(i);
	}
}
int main(){
	IOS;
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0,a,b;i<q;i++){
		cin>>a>>b;
		b+=n;
		E[a].pb(b);
		E[b].pb(a);
	}
	int cnt = 0;
	for(int i=1;i<=n+m;i++){
		if(!vis[i])dfs(i),cnt++;
	}
	cout<<cnt-1<<'\n';
}

