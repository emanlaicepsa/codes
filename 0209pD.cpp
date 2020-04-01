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
pii arr[100005];
vector<pii> edg;
pii operator - (pii a,pii b){
	return {a.fi - b.fi , a.se -b.se};
}
pii operator * (pii a, ll b){
	return {a.fi*b,a.se*b};
}
int main(){
	int n;
	cin>>n;
	if(n&1){
		cout<<"NO\n";
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>arr[i].fi>>arr[i].se;
	}
	arr[n] = arr[0];
	for(int i=0;i<n;i++){
		edg.pb(arr[i+1] - arr[i]);
	}
	int x = n/2;
	for(int i=0;i<x;i++){
		if(edg[i] != edg[i+x]*-1){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
}

