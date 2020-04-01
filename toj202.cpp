#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
vector<pii> con[105];
int ans[105][105];
int le[105][105];
int n,m,k,s,e,w,q;

struct pt{
	int na;
	int co;
	int le;
};
struct cmp{
	bool const operator()(const pt &a,const pt &b){
		return a.co==b.co?a.le>b.le:a.co<b.co; 
	}
};


priority_queue<pt,vector<pt>,cmp> pq;


void dijkstra(int x){
	//cout<<x<<'\n';
	ans[x][x]=0;
	pq.push({x,0,0});
	
	while(!pq.empty()){
		auto i=pq.top();pq.pop();
		//cout<<i.na<<" "<<i.co<<" "<<i.le<<'\n';
		
		
		for(auto &j:con[i.na]){
			if(i.co>ans[x][j.fi]) continue;
			if(i.le>=j.se){
				if(i.co<ans[x][j.fi]){
					pq.push({j.fi,i.co,i.le-j.se});
					ans[x][j.fi]=i.co;
					le[x][j.fi]=i.le-j.se;
				}
				else if(i.co==ans[x][j.fi]&&i.le-j.se>le[x][j.fi]){
					pq.push({j.fi,i.co,i.le-j.se});
					ans[x][j.fi]=i.co;
					le[x][j.fi]=i.le-j.se;
				}
			}
			else{
				if(i.co+1<=ans[x][j.fi]){
					pq.push({j.fi,i.co+1,k-j.se});
					ans[x][j.fi]=i.co+1;
					le[x][j.fi]=k-j.se;
				}
			}
		}
	}
}


int main(){
	IOS;
	memset(ans,0x3f,sizeof(ans));
	
	cin>>n>>m>>k;
	
	for(int i=0;i<m;i++){
		cin>>s>>e>>w;
		if(w<=k){
			con[s].emplace_back(e,w);
		    con[e].emplace_back(s,w);
		}
	}
	
	for(int i=0;i<n;i++){
		dijkstra(i);
	}
	
	cin>>q;
	while(q--){
		cin>>s>>e;
		if(ans[s][e]>1000000)cout<<"Impossible\n";
		else cout<<ans[s][e]<<'\n';
	}


}

/*
5 5 5
1 4 3
2 3 5
0 1 2
1 2 4
1 3 6
5
1 2
2 3
0 4
1 0
0 2
*/
 
