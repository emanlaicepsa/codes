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

ll bit[400010];
ll in[200005];
ll out[200005];
int dep[200005];
vector<int> E[200005];
ll arr[200005];
int id = 0;
int n,m,a,b,c;
void dfs(int x,int p){
	if(!p)dep[x] = 0;
	else dep[x] = dep[p] + 1;
	in[x] = ++id;
	for(auto &i:E[x]){
		if(i==p)continue;
		dfs(i,x);
	}
	out[x] = ++id;
}

void add(int pos,ll val){
	for(int i=pos;i<=2*n;i+=(i&-i))bit[i] += val;
}

ll que(int pos){
	ll ans = 0;
	for(int i=pos;i;i-=(i&-i))ans += bit[i];
	return ans;
}

int main(){
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1,a,b;i<=n-1;i++){
		cin>>a>>b;
		E[a].pb(b);
		E[b].pb(a);
	}
	dfs(1,0);
	while(m--){
		cin>>a;
		if(a==1){
			cin>>b>>c;
			if(dep[b]&1) c = -c;
			add(in[b],c);
			add(out[b],-c);
		}
		else{
			cin>>b;
			ll ans = que(in[b]);
			if(dep[b]&1) ans = -ans;
			cout<<arr[b]+ans<<'\n';
		}
		/*for(int i=1;i<=n;i++){
			ll ans = que(in[i]);
			if(dep[i]&1) ans = -ans;
			cout<<arr[i]+ans<<'\n';
		}*/
	}
}

