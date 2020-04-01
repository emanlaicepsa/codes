#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
struct edge{
	ll s;
	ll e;
	ll c;
};
vector<edge> v;
int fa[10005];
inline int findf(int x){
	if(x==fa[x])return x;
	return fa[x]=findf(fa[x]);
}
int main(){
	int n,m;
	cin>>n>>m;
	ll ai,bi,wi;
	ll ori=0;
	for(int i=0;i<m;i++){
		cin>>ai>>bi>>wi;
		v.push_back({ai,bi,wi});
		if(i<n-1)ori+=wi;
	}
	sort(v.begin(),v.end(),[](edge &a, edge &b){
		return a.c<b.c;
	});
	int cnt=0;
	ll newans=0;
	for(int i=0;i<n;i++)fa[i]=i;
	for(int i=0;i<m;i++){
		if(cnt==n-1)break;
		if(findf(v[i].s)!=findf(v[i].e)){
			fa[fa[v[i].s]]=fa[v[i].e];
			cnt++;
			newans+=v[i].c;
		}
	}
	if(cnt<n-1)cout<<-1<<'\n';
	//ll ans=ori-newans;
	else cout<<newans<<'\n';

}

