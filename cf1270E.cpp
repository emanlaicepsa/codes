#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define int ll
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
pii arr[1005];
int pa[1005];
inline ll calc(int x,int y){
	return (arr[x].fi-arr[y].fi)*(arr[x].fi-arr[y].fi)+(arr[x].se-arr[y].se)*(arr[x].se-arr[y].se);
}
int fp(int x){
	if(x==pa[x])return x;
	return pa[x]=fp(pa[x]);
}
void merge(ll x,ll y){
	if(fp(x)==fp(y))return;
	pa[fp(x)]=fp(y);
}
int col[1005];
signed main(){
	IOS
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		pa[i]=i;
		cin>>arr[i].fi>>arr[i].se;
	}
	unordered_map<ll,int> am;
	for(int i=1;i<=n;i++){
		unordered_map<ll,int> m;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			ll dis=calc(i,j);
			if(m.find(dis)!=m.end()){
				merge(j,m[dis]);
			}
			else{
				m[dis]=j;
			}
		}
		for(auto x:m){
			cout<<x.fi<<'\n';
			if(am.find(x.fi)!=am.end()){
				merge(am[x.fi],m[x.fi]);
			}
			else{
				am[x.fi]=m[x.fi];
			}
		}
	}
	int nc=1;
	for(int i=1;i<=n;i++){
		if(col[i])continue;
		if(!col[fp(i)]){
			col[fp(i)]=col[i]=nc;
			nc=3-nc;
		}
		else col[i]=col[fp(i)];
	}
	int cnt=0;
	vector<int> t;
	for(int i=1;i<=n;i++){
		//cout<<fp(i)<<'\n';
		//cout<<col[i]<<'\n';
		if(col[i]==1)cnt++,t.pb(i);
	}
	cout<<cnt<<'\n';
	for(auto i:t)cout<<i<<" ";
	cout<<'\n';
}

