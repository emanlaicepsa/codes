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
vector<int> E[5005];
ll num[5005];
int dep[5005];
int pa[5005];
struct q{
	int l,r,v;
};
vector<q> v;
void dfs(int x,int p){
	dep[x] = dep[p] +1;
	pa[x] = p;
	for(auto i:E[x]){
		if(i==p)continue;
		dfs(i,x);
	}
}
void col(int a,int b,ll v){
	if(dep[a] < dep[b])swap(a,b);
	while(dep[a] > dep[b]){
		num[a] = max(num[a],v);
		a = pa[a];
	}
	while(a!=b){
		num[a] = max(num[a],v);
		num[b] = max(num[b],v);
		a = pa[a];
		b = pa[b];
	}
}
ll que(int a,int b){
	ll cmin = 1e9;
	if(dep[a] < dep[b])swap(a,b);
	while(dep[a] > dep[b]){
		cmin = min(cmin,num[a]);
		a = pa[a];
	}
	while(a!=b){
		cmin = min(cmin,num[a]);
		cmin = min(cmin,num[b]);
		a = pa[a];
		b = pa[b];
	}
//	cout<<a<<" "<<b<<" "<<cmin<<'\n';
	return cmin;
} 
vector<pii> edg;
int main(){
	IOS;
	ll n,m;
	cin>>n;
	for(int i=1;i<=n;i++)num[i] = 1;
	edg.resize(n-1);
	for(int i=0,a,b;i<n-1;i++){
		cin>>a>>b;
		E[a].pb(b);
		E[b].pb(a);
		edg[i] = {a,b};
	}
	dfs(1,0);
	for(auto &i:edg){
		if(dep[i.fi] < dep[i.se])swap(i.fi,i.se);
	}
	cin>>m;
	v.resize(m);
	for(int i=0;i<m;i++){
		cin>>v[i].l>>v[i].r>>v[i].v;
	}
	for(auto i:v){
		col(i.l,i.r,i.v);
	}
	/*for(int i=1;i<=n;i++){
		cout<<num[i]<<'\n';
	}*/
	bool ok = 1;
	for(auto i:v){
		if(que(i.l,i.r)!=i.v){
			ok = 0;
			break;
		}
	}
	if(!ok)cout<<-1<<'\n';
	else{
		for(auto i:edg){
			cout<<num[i.fi]<<" ";
		}
	}
}

