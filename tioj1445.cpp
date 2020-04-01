#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(k,n) for(int k=0;k<(n);k++)
#define rep1(k,n) for(int k=1;k<=(n);k++)
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define vi vector<int>
//#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,ll>;
struct edge{
	int s;
	int e;
	ll w;
	bool operator<(const edge &a){
		return w<a.w;
	}
};
vector<edge> v;
vector<edge> q;
int pa[1005];
int rk[1005];
int p[1005][12];
vector<pii> E[1005];
ll maxe[1005][12];
int dep[1005];
int findf(int x){
	if(x==pa[x])return x;
	return pa[x]=findf(pa[x]);
}
void uni(int a,int b){
	if(rk[a]>rk[b])pa[b]=a;
	else if(rk[b]>rk[a])pa[a]=b;
	else pa[a]=b,rk[b]++;
}
void dfs(int nd,int pp,ll val){
	p[nd][0]=pp;
	maxe[nd][0]=val;
	for(int i=1;i<=11;i++) {
		p[nd][i]=p[p[nd][i-1]][i-1];
		maxe[nd][i]=max(maxe[nd][i-1],maxe[p[nd][i-1]][i-1]);
	}
	for(auto i:E[nd]){
		if(i.fi==pp)continue;
		dep[i.fi]=dep[nd]+1;
		dfs(i.fi,nd,i.se);
	}
}
ll qry(int a,int b){
//	cout<<a<<" "<<b<<"in\n";
	ll maxa=0,maxb=0;
	if(dep[a]<dep[b])swap(a,b);
	for(int tk=dep[a]-dep[b],cnt=0;tk;tk>>=1,cnt++){
		if(tk&1)maxa=max(maxa,maxe[a][cnt]),a=p[a][cnt];
	}
//	cout<<a<<" "<<b<<"jump\n";
	if(a==b)return max(maxa,maxb);
	for(int i=11;i>=0;i--){
		if(p[a][i]!=p[b][i]){
			maxa=max(maxa,maxe[a][i]),maxb=max(maxb,maxe[b][i]);
			a=p[a][i],b=p[b][i];
		}
	}
	/*while(a!=b){
		maxa=max(maxa,maxe[a][0]);
		maxb=max(maxb,maxe[b][0]);
		a=p[a][0];
		b=p[b][0];
	}*/
	maxa=max(maxa,maxe[a][0]),maxb=max(maxb,maxe[b][0]);
	a=p[a][0],b=p[b][0];
//	cout<<max(maxa,maxb)<<'\n';
	return max(maxa,maxb);
}
signed main(){
	IOS;
	int n,m,t1,t2,t3;
	cin>>n>>m;
	rep1(i,n)pa[i]=i,rk[i]=1;
	while(m--){
		cin>>t1>>t2>>t3;
		//assert(t1!=t2);
		if(t1==t2)continue;
		v.pb({t1,t2,t3});
	} 
	//assert(n>1);
	sort(all(v));
	int le=n-1;
	ll ans1=0;
	for(int i=0;i<v.size();i++){
		if( !le || (findf(v[i].s)==findf(v[i].e)) ) q.pb({v[i].s,v[i].e,v[i].w});
		else{
			//cout<<v[i].s<<" "<<v[i].e<<'\n';
			uni(pa[v[i].s],pa[v[i].e]),le--,ans1+=v[i].w;
			E[v[i].s].pb({v[i].e,v[i].w}),E[v[i].e].pb({v[i].s,v[i].w});
		}
	}
	if(le>0){
		cout<<"-1 -1\n";
		return 0;
	}
	//cout<<ans1<<'\n';
	if(q.empty()){
		cout<<ans1<<" -1\n";
		return 0;
	}
	ll ans2=ans1+q[0].w;
	
	for(int i=0;i<=11;i++)p[1][i]=0;
	dep[1]=0;
	dfs(1,0,0);
	/*rep1(j,n){
		rep(k,12){
			cout<<j<<" "<<k<<" "<<maxe[j][k]<<'\n';
		}
	}*/
	/*rep1(i,n){
		rep1(j,n){
			cout<<i<<" "<<j<<" "<<qry(i,j)<<'\n';
		}
	}*/
	for(auto i:q){
		ans2=min(ans2,ans1-qry(i.s,i.e)+i.w);
	}
	cout<<ans1<<" "<<ans2<<'\n';
}

