#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
vector<int> con[50005];
int cost[50005];
int cnt;
int flatree[100010];
int bit[100010];
int in[50005];
bool vis[50005];
int n,m;
inline int lb(int x){
	return x&-x;
}
void dfs(int x){
	vis[x]=1;
	flatree[++cnt]=cost[x];
	in[x]=cnt;
	for(int i:con[x]){
		if(!vis[i]){
			dfs(i);
		}
	}
	flatree[++cnt]=-cost[x];
}
void add(int x,int val){
	for(int i=x;i<=n*2;i+=lb(i)){
		bit[i]+=val;
	}
}
int query(int x){
	int ans=0;
	for(int i=x;i>0;i-=lb(i)){
		ans+=bit[i];
	}
	return ans;
}
int main(){
	IOS
	cin>>n>>m;
	int t1,t2;
	for(int i=0;i<n-1;i++){
		cin>>t1>>t2;
		con[t1].emplace_back(t2);
		con[t2].emplace_back(t1);
	} 
	for(int i=1;i<=n;i++){cin>>cost[i];}
	dfs(1);
	for(int i=1;i<=2*n;i++){add(i,flatree[i]);}
	char c;
	int x,w;
	ll ans=0;
	while(m--){
		cin>>c;
		if(c=='C'){
			cin>>x>>w;
			add(in[x],w-cost[x]);
			add(out[x],-w+cost[x]);
			cost[x]=w;
		}
		else{
			cin>>x;
			ans+=query(in[x]);
		}
	}
	cout<<ans<<'\n';
}

