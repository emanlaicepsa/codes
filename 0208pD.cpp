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

vector<ll> v;


int main(){
	v.pb(0);
	v.pb(1);
	while(1){
		int s = v.size();
		v.pb(v[s-1] + v[s-2]);
		//cout<<v[s]<<'\n';
		if(v[s] > 1e18)break;
	}
	for(int i=1;i<v.size();i++){
		v[i] += v[i-1];
		//cout<<v[i]<<'\n';
	}
	
	ll n;
	cin>>n;
	cout<<lower_bound(all(v),n) - v.begin() -1<<'\n';
	
}

