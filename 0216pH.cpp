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
bool po[300005];
map<pii,int> num;
vector<pii> E[300005];
bool vis[300005];
bool del[300005];
bool used[300005];
int ans = 0;
ll n,k,d;
queue<pii> q;
int main(){
	IOS;
	cin>>n>>k>>d;
	for(int i=1,a;i<=k;i++){
		cin>>a;
		po[a] = 1;
		vis[a] = 1;
		q.push({a,0});
	}
	for(int i=1,a,b;i<=n-1;i++){
		cin>>a>>b;
		E[a].pb({b,i});
		E[b].pb({a,i});
	}
	
	while(!q.empty()){
		auto x = q.front() ;q.pop();
		//if(x.se == d)continue;
		for(auto i:E[x.fi]){
			if(del[i.se])continue;
			if(used[i.se])continue;
			if(vis[i.fi]){
				del[i.se] = 1;
				ans ++;
				continue;
			} 
			used[i.se] = 1 ;
			vis[i.fi] = 1;
			q.push({i.fi,x.se+1});
		}		
	}
	
	cout<<ans<<'\n';
	for(int i=1;i<=n-1;i++){
		if(del[i])cout<<i<<" ";
	}

}

