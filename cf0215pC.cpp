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
struct cus{
	ll t;
	ll l;
	ll r;
	bool operator<(const cus& x){
		return t<x.t;
	}
};
vector<cus> v;
ll nlow,nhigh,ntime;

int main(){
	IOS;
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		v.clear();
		v.resize(n);
		for(int i=0;i<n;i++){
			cin>>v[i].t>>v[i].l>>v[i].r;
		}
		sort(all(v));
		nlow = nhigh = m;
		ntime = 0;
		bool ok = 1;
		for(int i=0;i<n;i++){
			nhigh += v[i].t-ntime;
			nlow -= v[i].t-ntime;
			if(nhigh < v[i].l || nlow > v[i].r){
				ok = 0;
				break;
			}
			nhigh = min(nhigh,v[i].r);
			nlow = max(nlow,v[i].l);
			ntime = v[i].t;
		}
		if(ok)cout<<"YES\n";
		else cout<<"NO\n";
	}


}

