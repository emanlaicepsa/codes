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
vector<int> E[30005];
int pa[30005][18];
int dep[30005];

void dfs(int x,int p){
	pa[x][0] = p;
	dep[x] = dep[p] + 1;
	for(int i=1;i<18;i++){
		pa[x][i] = pa[ pa[x][i-1] ][i-1];
	}
	for(auto i:E[x]){
		dfs(i,x);
	}
}

pii que(int x,int y){
	int ans = 0;
	if(dep[x] < dep[y])swap(x,y);
	
	int de = dep[x] - dep[y];
	//cout<<de<<'\n';
	for(int i=17;i>=0;i--){
		if(de >= (1<<i)){
			//cout<<de<<" "<<i<<'\n';
			de -= (1<<i);
			x = pa[x][i];
			ans += (1<<i);
		}
	}
	//cout<<ans<<'\n'; 
	if(x==y)return {x,ans};
	
	for(int i=17;i>=0;i--){
		if(pa[x][i] != pa[y][i]){
			ans += (1<<i) * 2;
			x = pa[x][i];
			y = pa[y][i];
		}
	}
	
	return {pa[x][0],ans+2};
}

int main(){
	IOS;
	int n,q;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		int x;
		while(1){
			cin>>x;
			if(x==0)break;
			E[i].pb(x);
		}
	}
	
	dfs(1,0);
	
	int a,b; 
	while(q--){
		cin>>a>>b;
		pii tmp = que(a,b);
		cout<<tmp.fi<<" "<<tmp.se<<'\n';
	}


}

