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
int n;
bool ok(ll m){
	int cur = 0,line = 1;
	for(auto &i:v){
		if(cur + i > m){
			cur = 0;
			line++;
		}
		cur+=i;
	}
	return (line<=n);
}
int main(){
	IOS;
	string s;
	cin>>n;
	cin.ignore();
	getline(cin,s);
	int cnt = 0;
	for(auto &i:s){
		cnt++;
		if(i==' '||i=='-'){
			v.pb(cnt);
			cnt = 0;
		}
	}
	v.pb(cnt);
	ll l = 0,r = 1000007;
	for(auto &i:v){
		l = max(l,i);
		//cout<<i<<" ";
	}
	while(l<r){
		ll m = (l+r)>>1;
		if(ok(m)){
			r=m;
		}
		else l=m+1;
	}
	cout<<l<<'\n';

}

