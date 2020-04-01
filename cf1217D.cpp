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
vector<pii> E[5005];
bool instk[5005];
bool vis[5005];
int col[5005];
bool two = 0;
void dfs(int x){
	instk[x] = 1;
	vis[x] = 1;
	for(auto i:E[x]){
		if(vis[i.fi]){
			if(instk[i.fi]){
				col[i.se] =2;
				two = 1;
			}
		}
		else{
			dfs(i.fi);
		}
	}
	
	instk[x] = 0;
}

int main(){
	IOS;
	int n,m;
	cin>>n>>m;
	for(int i=0,a,b;i<m;i++){
		cin>>a>>b;
		E[a].pb({b,i});
		col[i] = 1;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])dfs(i);
	} 
	cout<<1+two<<'\n';
	for(int i=0;i<m;i++){
		cout<<col[i]<<" \n"[i==m-1];
	}
}

