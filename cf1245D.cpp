#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
struct edge{
	ll s;
	ll e;
	ll c;
};
bool operator<(const edge &a,const edge &b){
	return a.c > b.c; 
}
priority_queue<edge> pq; 
pii arr[2005];
ll c[2005];
ll k[2005];
int pa[2005];
ll calc(ll i,ll j){
	return (abs(arr[i].fi - arr[j].fi) + abs(arr[i].se - arr[j].se)) * (k[i] + k[j]);
}

int fp(int x){
	if(x==pa[x])return x;
	return pa[x] = fp(pa[x]);
}

bool merge(int x,int y){
	x = fp(x),y = fp(y);
	if(x==y)return false;
	pa[x] = y;
	return true;
}


int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].fi>>arr[i].se;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		pq.push({0,i,c[i]});
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	for(int i=1;i<=n;i++){
		for(int j =i+1;j<=n;j++){
			pq.push({i,j,calc(i,j)});
		}
	}
	ll siz = n+1;
	ll ans = 0;
	vector<int> build;
	vector<pii> con;
	for(int i=0;i<=n;i++){
		pa[i] = i;
	}
	while(siz>1){
		edge x = pq.top();pq.pop();
		if(merge(x.s,x.e)){
			siz--;
			ans += x.c;
			if(x.s){
				con.pb({x.s,x.e});
			}
			else{
				build.pb(x.e);
			}
		}
		//cout<<x.s<<" "<<x.e<<" "<<x.c<<'\n';
	}
	cout<<ans<<'\n';
	cout<<build.size()<<'\n';
	for(auto &i:build)cout<<i<<" ";
	cout<<'\n';
	cout<<con.size()<<'\n';
	for(auto &i:con)cout<<i.fi<<" "<<i.se<<'\n';

}

