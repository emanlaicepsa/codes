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
using namespace std;
using ll=long long;
using pii=pair<int,int>;
struct edge{
	int s;
	int e;
	ll w;
	bool operator<(const edge &b){
		return w<b.w;
	}
};
vector<edge> v;
int pa[100005];
int rk[100005];
int findf(int x){
	if(x==pa[x])return x;
	return pa[x]=findf(pa[x]);
}
void uni(int a,int b){
	if(rk[a]>rk[b]){
		pa[b]=a;
	}
	else if(rk[b]>rk[a]){
		pa[a]=b;
	}
	else{
		pa[b]=a;
		rk[a]++;
	}
}
int main(){
	IOS;
	int n,m,k,ta,tb,tc;
	cin>>n>>m>>k;
	rep1(i,n)pa[i]=i,rk[i]=1;
	v.clear();
	while(m--){
		cin>>ta>>tb>>tc;
		v.pb({ta,tb,tc});
	}
	sort(all(v));
	ll ans=0;
	ll le=n-1;
	for(auto i:v){
		if(findf(i.s)!=findf(i.e))uni(pa[i.s],pa[i.e]),le--,ans+=i.w;
	}
	if(le)cout<<"NIE\n";
	int minn=ans;
	reverse(all(v));
	rep1(i,n)pa[i]=i,rk[i]=1;
	ans=0;
	for(auto i:v){
		if(findf(i.s)!=findf(i.e))uni(pa[i.s],pa[i.e]),ans+=i.w;
	}
	int maxx=ans;
	if(minn<=k&&maxx>=k)cout<<"TAK\n";
	else cout<<"NIE\n";


}

