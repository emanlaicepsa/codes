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
int arr[200005];
int arr2[200005];
vector<int> E[200005],E2[200005];
bool vis[200005];
int id,sccid,tmp;
int l[200005];
int d[200005];
stack<int> stk;
bool instk[200005];
int scc[200005];
int in[200005];
int num[200005];
queue<int> q;
void dfs(int nd){
	l[nd]=d[nd]=++id;
	vis[nd]=1;
	stk.push(nd);instk[nd]=1;
	for(auto i:E[nd]){
		if(!vis[i]){
			dfs(i);
			l[nd]=min(l[nd],l[i]); 
		}
		else if(instk[i]){
			l[nd]=min(l[nd],d[i]);
		}
	}
	if(l[nd]==d[nd]){
		sccid++;
		do{
			tmp = stk.top();stk.pop();instk[tmp]=0;
			scc[tmp]=sccid;	
		}while(tmp!=nd);
	}
}
int main(){
	IOS
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n-1;i++){
		E[arr[i]].pb(arr[i+1]);
	}
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n-1;i++){
		if(E[arr[i]].empty()||E[arr[i]][0]!=arr[i+1])E[arr[i]].pb(arr[i+1]);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])dfs(i);
	}
	if(sccid<k){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++){
		//cout<<scc[i]<<'\n';
		for(auto j:E[i]){
			if(scc[i]!=scc[j])E2[scc[i]].pb(scc[j]),in[scc[j]]++; 
		}
	}
	int nid=0;
	for(int i=1;i<=sccid;i++){
		if(in[i]==0){
			num[i]=nid++;
			q.push(i);
		}
	}
	while(!q.empty()){
		int x = q.front();q.pop();
		for(auto i: E2[x]){
			in[i]--;
			if(in[i]==0)q.push(i),num[i]=nid++;
			if(nid>25)nid--; 
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<<char(num[scc[i]]+'a');
	}
}

