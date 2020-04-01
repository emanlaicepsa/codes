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

ll n,k;
int bit[20005];
void add(int x){
	for(int i=x;i<=n+1;i+=(i&-i))bit[i]++;
}
int query(int x){
	int ans = 0;
	for(int i=x;i;i-=(i&-i))ans+=bit[i];
	return ans;
}

int arr[20005];
int l[20005];
vector<int> tosort;

ll check(ll x){
	ll ans = 0;
	memset(bit,0,sizeof(bit));
	memset(l,0,sizeof(l));
	int nidx = 0;
	for(int i=0;i<=n;i++){
		while(nidx<=n && tosort[i] - tosort[nidx] > x) nidx++;
		l[i] = nidx-1;
		//cout<<i<<" "<<l[i]<<'\n';
	}
	
	for(int i=0;i<=n;i++){
		//cout<<arr[i]<<" "<<l[arr[i]]<<'\n';
		ans += query(l[arr[i]]+1);
		add(arr[i]+1);
	}
	
	//cout<<x<<" "<<ans<<'\n';
	return ans;
}

int main(){
	IOS;
	while(cin>>n>>k){
		tosort.clear();
		tosort.pb(0);
		if(n==0&&k==0)break;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			arr[i] += arr[i-1];
			tosort.pb(arr[i]); 
		}
		sort(all(tosort));
		tosort.resize(unique(all(tosort))-tosort.begin());
		for(int i=0;i<=n;i++){
			arr[i] = lower_bound(all(tosort),arr[i]) - tosort.begin();
		}
		ll l = -2e9 , r=2e9;
		while(l<r){
			ll m = (l+r)>>1;
			if(check(m)<k){
				r=m;
			}
			else{
				l=m+1;
			}
		} 
		cout<<l<<'\n';
	}


}

