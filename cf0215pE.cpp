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
int pa[100005][20];
vector<int> E[100005];
int dep[100005];

void dfs(int x,int p){
	pa[x][0] = p;
	dep[x] = dep[p] + 1;
	for(int i=1;i<=18;i++){
		pa[x][i] = pa[pa[x][i-1]][i-1];
	}
	for(auto &i:E[x]){
		if(i==p)continue;
		dfs(i,x);
	}
}

int dis(int x,int y){
	if(dep[x] < dep[y])swap(x,y);
	int de = dep[x] - dep[y];
	int ans = 0;
	for(int i=18;i>=0;i--){
		if(de&(1<<i)){
			x = pa[x][i];
			ans += (1<<i);
		}
	}
	if(x==y)return ans;
	for(int i=18;i>=0;i--){
		if(pa[x][i] != pa[y][i]){
			ans += (1<<i) * 2;
			x = pa[x][i];
			y = pa[y][i];
		}
	}
	return ans+2;
}

int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=1,a,b;i<=n-1;i++){
		cin>>a>>b;
		E[a].pb(b);
		E[b].pb(a);
	}
	dfs(1,0);
	int m,x,y,a,b,k;
	cin>>m;
	while(m--){
		ll odd = 1e18,even = 1e18;
		cin>>x>>y>>a>>b>>k;
		ll td;
		td = dis(a,b);
		//cout<<td<<'\n';
		if(td&1){
			odd = min(odd,td);
		} 
		else{
			even = min(even,td);
		}
		td = dis(a,x) + dis(b,y) + 1;
		//cout<<td<<'\n';
		if(td&1){
			odd = min(odd,td);
		} 
		else{
			even = min(even,td);
		}
		td = dis(a,y) + dis(b,x) + 1;
		//cout<<td<<'\n';
		if(td&1){
			odd = min(odd,td);
		} 
		else{
			even = min(even,td);
		}
		if(k&1){
			if(odd<=k){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";
			}
		}
		else{
			if(even<=k){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";
			}
		}
	}


}

