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
bool vis[805];
vector<int> E[805];
void dfs(int x){
	vis[x] = 1;
	for(auto i:E[x]){
		if(!vis[i])dfs(i);
	}
}
int main(){
	IOS;
	int n,m,x,y;
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			vis[i] = 0;
			E[i].clear();
		}
		for(int i=0,a,b;i<m;i++){
			cin>>a>>b;
			E[a].pb(b);
		}
		cin>>x>>y;
		dfs(x);
		if(vis[y])cout<<"Yes!!!\n";
		else cout<<"No!!!\n";
	}
}

