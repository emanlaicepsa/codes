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
int col[10005];
vector<int> E[10005];
int cnt ;
void dfs(int x,int c){
	if(c!=col[x]){
		cnt++;
		c = col[x];
	}
	for(auto i:E[x]){
		dfs(i,c);
	}
}
int main(){
	IOS;
	int n,x;
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>x;
		E[x].pb(i);
	}
	for(int i=1;i<=n;i++){
		cin>>col[i];
	}
	dfs(1,0);
	cout<<cnt<<'\n';
}

