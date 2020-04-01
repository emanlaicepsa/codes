#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
struct edge{
	int s;
	int e;
	int v;
};
vector<edge> sides;
vector<pair<int,int>> queries; 
ll ans[1000005];
int fa[50000];
ll num[50000];
int findf(int x){
	if(fa[x]==x)return x;
	else return fa[x]=findf(fa[x]);
}


int main(){
	IOS
	int N,M,Q;
	cin>>N>>M>>Q;
	sides.resize(M);
	for(int i=0;i<M;i++){
		cin>>sides[i].s>>sides[i].e>>sides[i].v;
	}
	for(int i=1;i<=N;i++){
		fa[i]=i;
		num[i]=1;
	}
	
	int temp;
	for(int i=0;i<Q;i++){
		cin>>temp;
		queries.emplace_back(temp,i);
	}
	sort(sides.begin(),sides.end(),[](edge &a,edge &b){
		return a.v<b.v;
	});
	sort(queries.begin(),queries.end());
	ll tans=0;
	int index=0;
	for(int i=0;i<Q;i++){
		while((index<M)&&(sides[index].v<=queries[i].first)){
			if(findf(sides[index].e)!=findf(sides[index].s)){
				int fx=fa[sides[index].e];
				int fy=fa[sides[index].s];
				tans-=num[fx]*(num[fx]-1);
				tans-=num[fy]*(num[fy]-1);
				fa[fy]=fx;
				num[fx]+=num[fy];
				num[fy]=0;
				tans+=num[fx]*(num[fx]-1);
			}
			index++;
		}
		ans[queries[i].second]=tans;
	}
	for(int i=0;i<Q;i++){
		cout<<ans[i]<<'\n';
	}
	
	
	
	

}

