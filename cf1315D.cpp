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
priority_queue<ll> pq;
int main(){
	IOS;
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].fi;
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i].se;
	}
	sort(arr+1,arr+1+n);
	
	ll ans = 0;
	ll cursum = 0;
	
	int nidx = 1;
	int nx = 0;
	int cnt = 0;
	
	while(cnt<n){
		if(pq.empty()) nx = arr[nidx].fi;
		else{
			nx ++;
			ans += cursum;
		}	
		while(nidx<=n&&arr[nidx].fi == nx){
			pq.push(arr[nidx].se);
			cursum += arr[nidx].se;
			nidx++;
		}
		cursum -= pq.top();
		pq.pop();
		cnt++;
	}
	
	cout<<ans<<'\n';

}

