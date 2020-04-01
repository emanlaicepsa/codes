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
inline int yes(int x){
	return x*2;
}
inline int no(int x){
	return x*2+1;
}
vector<int> E1[210],E2[210];
inline void build(int x,int y){
	E1[x].pb(y);
	E2[y].pb(x);
}
 
bool vis[210];
bool vis2[210];
vector<int> ord;
int scc[210];
int nid = 0;
int cho[210];
bool ok = 1;
void dfs2(int x){
	vis2[x] = 1;
	for(auto i:E2[x]){
		if(!vis2[i])dfs2(i);
	}
}

void dfs1(int x){
	vis[x] = 1;
	for(auto i:E1[x]){
		if(!vis[i])dfs1(i);
	}
	if(!vis2[x]){
		cho[x] = 1;
		dfs2(x^1);
		if(vis2[x]){
			ok = 0;
		}
	}
}
 

 
 
int main(){
	IOS;
	int n,m;
	cin>>n>>m;
	
	for(int i=0,a,b,c;i<m;i++){
		cin>>a>>b>>c;
		if(c){
			build(yes(a),yes(b));
			build(no(a),no(b));
			build(no(b),no(a));
			build(yes(b),yes(a));
		}
		else{
			build(no(a),yes(b));
			build(no(b),yes(a));
			build(yes(b),no(a));
			build(yes(a),no(b));
		}
	}
	for(int i=1;i<=2*n;i++){
		if(!vis[i])dfs1(i);
	}
	
	if(!ok){
		cout<<"Impossible\n";
		return 0;
	}
	
	
	vector<int> ans;
	for(int i=1;i<=n;i++){
		if(cho[yes(i)] == 1){
			ans.pb(i);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans){
		cout<<i<<" ";
	}
	cout<<'\n';
}
