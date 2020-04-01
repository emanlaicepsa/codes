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
int col[100005];
map<int,int> m[100005];
int mxson[100005];
int siz[100005];
ll ans[100005];
int mxcnt[100005];
vector<int> E[100005];
void dfs(int x,int p){
	siz[x] = 1;
	mxson[x] = 0;
	int mxsize = 0;
	for(auto &i : E[x]){
		if(i==p)continue;
		dfs(i,x);
		siz[x] += siz[i];
		if(siz[i] > mxsize){
			mxson[x] = i;
			mxsize = siz[i];
		}
	}
}

inline void add(int nd,int col,int num){
	m[nd][col] += num;
	int x = m[nd][col];
	if(x > mxcnt[nd]){
		ans[nd] = col;
		mxcnt[nd] = x;
	}
	else if(x == mxcnt[nd]){
		ans[nd] += col;
	}
}

void dfs2(int x,int p){
	if(mxson[x] == 0){
		//cout<<x<<'\n';
		m[x][col[x]] ++;
		ans[x] = col[x];
		mxcnt[x] = 1;
		return;
	}
	for(auto &i:E[x]){
		if(i==p)continue;
		dfs2(i,x);
	}
	swap(m[x],m[mxson[x]]);
	ans[x] = ans[mxson[x]];
	mxcnt[x] = mxcnt[mxson[x]];
	for(auto &i:E[x]){
		if(i==p||i==mxson[x]){
			continue;
		}
		for(auto &j:m[i]){
			add(x,j.fi,j.se);
		}
	}
	add(x,col[x],1);
}

int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>col[i];
	}
	for(int i=1,a,b;i<=n-1;i++){
		cin>>a>>b;
		E[a].pb(b);
		E[b].pb(a);
	}
	dfs(1,0);
	/*for(int i=1;i<=n;i++){
		cout<<mxson[i]<<'\n';
	}*/
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" \n"[i==n];
	}
}

