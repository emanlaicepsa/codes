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
pii arr[10005];
int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i].fi>>arr[i].se;
	}
	sort(arr,arr+n);
	ll ans = 0;
	ll nl=0, nr = 0;
	for(int i=0;i<n;i++){
		if(arr[i].fi > nr){
			ans += nr - nl;
			nl = arr[i].fi;
			nr = arr[i].se;
		}
		else{
			nr = max(nr,arr[i].se);
		}
	}
	ans += nr - nl;
	cout<<ans<<'\n';
}

