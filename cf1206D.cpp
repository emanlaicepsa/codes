#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
set<int> con[100005]; 
vector<int> cnt[63];
vector<pair<int,int>> edges;
bool vis[100005];
ll bfs(int s,int e){
	memset(vis,0,sizeof(vis));
	queue<pair<int,int>> q;
	q.push({s,0});
	while(!q.empty()){
		int node=q.front().first;
		int deep=q.front().second;
		q.pop();
		if(node==e)return deep+1;
		vis[node]=1;
		for(auto i:con[node]){
			if(!vis[i]){
				q.push({i,deep+1});
			}
		}
	}
	return 0x3f3f3f3f;
	
}



int main(){
	int n;
	cin>>n;
	ll temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		for(int j=0;j<63;j++){
			if(temp&(ll)1<<j){
				cnt[j].push_back(i);
			}
		}
	}
	for(int i=0;i<63;i++){
		if(cnt[i].size()>=3){
			cout<<3<<'\n';
			return 0;
		}
		else if(cnt[i].size()==2){
			con[cnt[i][0]].insert(cnt[i][1]);
			con[cnt[i][1]].insert(cnt[i][0]);
			edges.emplace_back(cnt[i][0],cnt[i][1]);
		}
	}
	ll ans=0x3f3f3f3f;
	for(auto edge: edges){
		int s=edge.first;
		int e=edge.second;
		con[s].erase(e);
		con[e].erase(s);
		ans=min(ans,bfs(s,e));
		con[s].insert(e);
		con[e].insert(s);
	}
	
	if(ans>1000005)cout<<-1<<'\n';
	else cout<<ans<<'\n';


}

