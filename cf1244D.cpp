#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;

ll co[5][100005];
int color[100005];
vector<int> con[100005];
vector<int> v={1,2,3};
vector<int> ansv;

ll dfs1(int nd,int p,int idx){
	ll ans=co[v[idx]][nd];
	for(auto i:con[nd]){
		if(i==p)continue;
		ans+=dfs1(i,nd,(idx+1)%3);
	}
	return ans;
}

void dfs2(int nd,int p,int idx){
	color[nd]=ansv[idx];
	for(auto i:con[nd]){
		if(i==p)continue;
		dfs2(i,nd,(idx+1)%3);
	}
	return;
}


int main(){
	int n,ta,tb,rt;
	cin>>n;
	
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++)
			cin>>co[i][j];
			
	for(int i=0;i<n-1;i++){
		cin>>ta>>tb;
		con[ta].emplace_back(tb);
		con[tb].emplace_back(ta);
	}
	
	for(int i=1;i<=n;i++){
		if(con[i].size()>=3){
			cout<<-1<<'\n';
			return 0;
		}
		if(con[i].size()==1){
			rt=i;
		}
	}
	
	ll ans=1e16;
	
	for(int i=0;i<6;i++){
		ll tem=dfs1(rt,0,0);
		if(tem<ans){
			ans=tem;
			ansv=v;
		}
		next_permutation(v.begin(),v.end());
	}
	
	cout<<ans<<'\n';
	dfs2(rt,0,0);
	for(int i=1;i<=n;i++){
		cout<<color[i]<<' ';
	}
	cout<<'\n';


}

