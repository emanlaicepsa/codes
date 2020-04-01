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
set<int> E[100005];
set<int> nvis;

void dfs(int x){
	//cout<<x<<'\n';
	vector<int> v;
	for(auto &i:nvis){
		if(E[x].find(i) == E[x].end()){
			v.pb(i);
		}
	}
	for(auto &i:v){
		nvis.erase(i);	
	}
	for(auto &i:v)dfs(i);
}

int main(){
	IOS;
	ll n,m;
	cin>>n>>m;
	for(int i=0,a,b;i<m;i++){
		cin>>a>>b;
		E[a].insert(b);
		E[b].insert(a);
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		nvis.insert(i);
	}
	for(int i=1;i<=n;i++){
		if(nvis.find(i) != nvis.end()){
			nvis.erase(i);
			dfs(i);
			cnt++;
		}
	}
	cout<<cnt-1<<'\n';


}

