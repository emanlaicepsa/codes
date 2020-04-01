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
int n,m;

vector<ll> val;
vector<ll> v;
vector<pii> E[20005];

int col[20005];

bool gd;
void dfs(int x,ll lim){
	if(!gd)return;
	for(auto i:E[x]){
		//cout<<i.fi<<" "<<i.se<<'\n';
		if(i.se >= lim){
			if(col[i.fi] == col[x]){
				gd = 0;
				return;
			}
			if(!col[i.fi]){
				col[i.fi] = 3 - col[x];
				dfs(i.fi,lim);
			}
		}
	}
}

bool ok(ll x){
	memset(col,0,sizeof(col));
	gd = 1;
	for(int i=1;i<=n;i++){
		if(!col[i]){
			col[i] = 1;
			dfs(i,x);
		}
	}
	/*for(int i=1;i<=n;i++){
		cout<<i<<" "<<col[i]<<'\n';
	}
	cout<<x<<" "<<gd<<'\n';*/
	return gd;
}

int main(){
	IOS;
	cin>>n>>m;
	for(ll i=0,a,b,c;i<m;i++){
		cin>>a>>b>>c;
		E[a].pb({b,c});
		E[b].pb({a,c});
		val.pb(c);
	}
	val.pb(1e18);
	sort(all(val));
	//for(auto i:val)cout<<i<<" ";
	int l = 0, r = m-1;
	
	while(l<r){
		int mid = (l+r)>>1;
		if(ok(val[mid])){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	if(l==0){
		cout<<0<<'\n';
	}
	else{
		cout<<val[l-1]<<'\n';
	}
	
}

