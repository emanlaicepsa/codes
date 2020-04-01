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
vector<int> E[200005];
ll siz[200005];
ll odd,even,n;
ll ans = 0;
void dfs(int x,int pa,int de){
	siz[x] = 1;
	if(de)odd++;
	else even++;
	for(auto i:E[x]){
		if(i==pa)continue;
		dfs(i,x,de^1);
		ans += siz[i] * (n-siz[i]);
		siz[x] +=siz[i];
	}
}
int main(){
	IOS;
	cin>>n;
	for(int i=0,a,b;i<n-1;i++){
		cin>>a>>b;
		E[a].pb(b);
		E[b].pb(a);
	}
	dfs(1,0,0);
	ans += odd*even;
	ans/=2;
	cout<<ans<<'\n';
}

