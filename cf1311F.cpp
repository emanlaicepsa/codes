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

pii arr[200005];
vector<ll> sortv;
int n;
pii bit[2][200005];

void add(int x,int idx,ll val){
	for(int i=idx;i<=n;i+=(i&-i)){
		bit[x][i].fi +=(val>0?1:-1); 
		bit[x][i].se +=val;
	}
}

pii query(int x,int idx){
	pii ans = {0,0};
	for(int i=idx;i;i-=(i&-i)){
		ans.fi += bit[x][i].fi;
		ans.se += bit[x][i].se;
		//cout<<"^"<<ans.fi<<" "<<ans.se<<'\n';
	}	
	//cout<<x<<" "<<idx<<" "<<ans.fi<<" "<<ans.se<<'\n';
	return ans;
}

int main(){
	IOS;
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i].fi;
	for(int i=1;i<=n;i++)cin>>arr[i].se , sortv.pb(arr[i].se);
	
	
	sort(arr+1,arr+1+n);
	sort(all(sortv));
	sortv.resize( unique(all(sortv)) - sortv.begin());
	
	for(int i=1;i<=n;i++){
		arr[i].se = lower_bound(all(sortv),arr[i].se) - sortv.begin() +1;
		//cout<<arr[i].fi<<" "<<arr[i].se<<'\n';
	}	
	
	ll rsiz = 0,rcnt = 0 ,ans = 0;
	for(int i=1;i<=n;i++){
		rsiz+=arr[i].fi;
		rcnt++;
		add(1,arr[i].se,arr[i].fi);
	}
	
	for(int i=1;i<=n;i++){
		add(1,arr[i].se,-arr[i].fi);
		rcnt--;
		rsiz-=arr[i].fi;
		pii tmp = query(0,arr[i].se);
		ans += (tmp.fi * arr[i].fi) - tmp.se;
		//cout<<ans<<'\n';
		tmp = query(1,arr[i].se-1);
		tmp.fi = rcnt - tmp.fi;
		tmp.se = rsiz - tmp.se;
		//cout<<tmp.fi<<" "<<tmp.se<<"^\n";
		ans += (tmp.se - arr[i].fi * tmp.fi);
		add(0,arr[i].se,arr[i].fi);
		//cout<<ans<<'\n';
	}

	cout<<ans/2<<'\n';
}

