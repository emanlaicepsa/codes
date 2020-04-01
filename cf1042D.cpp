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
ll s[200005];
ll n,t;
ll solve(int l,int r){
	if(l==r)return 0;
	ll ta = 0;
	int m = (l+r)>>1;
	ta += solve(l,m);
	ta += solve(m+1,r);
	int lidx = l,ridx = m+1;
	while(ridx <= r){
		while(lidx<=m && s[ridx] - t >= s[lidx])lidx ++;
		ta += m-lidx+1;
		ridx ++;
	}
	lidx = l,ridx = m+1;
	vector<ll> v;
	while(lidx<=m && ridx<=r){
		if(s[lidx] <= s[ridx])v.pb(s[lidx++]);
		else v.pb(s[ridx++]);
	}
	while(lidx<=m)v.pb(s[lidx++]);
	while(ridx<=r)v.pb(s[ridx++]);
	lidx = l;
	for(auto i:v){
		s[lidx++] = i;
	}
	//cout<<"$"<<" "<<l<<" "<<r<<'\n';
	//for(int i=l;i<=r;i++)cout<<s[i]<<" ";
	//cout<<'\n';
	//cout<<"%"<<" "<<ta<<'\n';
	return ta;
}

int main(){
	IOS;
	cin>>n>>t;
	ll ans = 0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i] += s[i-1];
	}
	/*for(int i=0;i<=n;i++){
		cout<<s[i]<<" ";
	}
	cout<<'\n';*/
	cout<<solve(0,n)<<'\n';
}

