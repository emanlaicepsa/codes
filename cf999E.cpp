#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define reset(x,n) memset((x),(n),sizeof(x))
#define all(n) (n).begin(),(n).end()
#define pb push_back
#define IOS ios::sync_with_stdio(0),cin.tie(0);
vector<int> v;
vector<int> E[5005];
int in[5005];
int out[5005];
int n,m,s,ta,tb;
bool vis[5005];
int cnt;
void dfs(int x){
	vis[x]=1;
	for(auto i:E[x]){
		if(!vis[i])dfs(i); 
	}
}
bool cmp(int x,int y){
	return in[x]-out[x]<in[y]-out[y];
}
int main(){
	IOS
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)v.pb(i);
	for(int i=1;i<=m;i++){
		cin>>ta>>tb;
		E[ta].pb(tb);
		in[tb]++;
		out[ta]++;
	}
	in[s]=-1e9;
	sort(all(v),cmp);
	for(auto i:v){
		//cout<<i<<'\n';
		if(!vis[i])dfs(i),cnt++; 
	}
	
	cout<<cnt-1<<'\n';
}

