#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(k,n) for(int k=0;k<(n);k++)
#define rep1(k,n) for(int k=1;k<=(n);k++)
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define vi vector<int>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll ti[10005];
vi E[10005];
int in[10005];
ll maxdis[10005];
vi pa[10005];
queue<int> q;
set<int> ans;
void dfs(int x){
	//cout<<"$"<<x<<'\n';
	ans.insert(x);
	for(auto i:pa[x]){
		dfs(i);
	}
}
int main(){
	IOS
	int n,m,t1,t2;
	while(cin>>n>>m){
		ans.clear();
		reset(ti,0);
		reset(in,0);
		reset(maxdis,0);
		while(!q.empty()) q.pop();
		rep1(i,10000) E[i].clear(),pa[i].clear();
		rep1(i,n) cin>>ti[i];
		rep1(i,m){
			cin>>t1>>t2;
			E[t1].pb(t2); 
			in[t2]++;
		}
		rep1(i,n){
			if(in[i]==0)q.push(i);
		}
		
		while(!q.empty()){
			int x=q.front();q.pop();
			maxdis[x]+=ti[x];
			if(E[x].empty()){
				
				if(maxdis[x]>maxdis[0]){
					//cout<<"%"<<x<<'\n';
					maxdis[0]=maxdis[x];
					pa[0].clear();
					pa[0].pb(x);
				}
				else if(maxdis[x]==maxdis[0]){
					//cout<<"q"<<x<<'\n';
					pa[0].pb(x);
				}
			}
			else{
				for(auto i:E[x]){
					if(maxdis[x]>maxdis[i]){
						maxdis[i]=maxdis[x];
						pa[i].clear();
						pa[i].pb(x);
					}
					else if(maxdis[x]==maxdis[i]){
						pa[i].pb(x); 
					} 
					in[i]--;
					if(!in[i])q.push(i);
				}
			}
		}
		/*rep1(i,n){
			cout<<i<<" "<<maxdis[i]<<'\n';
		}*/
		dfs(0);
		
		cout<<ans.size()-1<<'\n';
	}
	



}

