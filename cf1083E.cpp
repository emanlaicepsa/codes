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
struct line{
	ll m;
	ll k;
};
ll val(line a,ll x){
	return x* a.m + a.k;
}
bool intersect(line a,line b ,line c){
	return (b.k-a.k)*1.0 / (a.m-b.m) <= (c.k - b.k)*1.0 / (b.m - c.m);
}
struct rect{
	ll x,y,a;
};
vector<rect> v;
bool cmp(rect x,rect y){
	return x.x <y.x; 
}
deque<line> dq;
ll dp[1000005];
int main(){
	IOS;
	int n;
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i].x>>v[i].y>>v[i].a;
	}
	sort(v.begin(),v.end(),cmp);
	//for(auto i:v)cout<<i.x<<'\n';
	ll ans = 0;
	dq.pb({0,0});
	for(int i=0;i<n;i++){
		while(dq.size()>1 && val(dq[0],-v[i].y) <= val(dq[1],-v[i].y)) dq.pop_front();
	    dp[i] = val(dq[0] , -v[i].y) + v[i].x * v[i].y - v[i].a ;
		line tmp = { v[i].x , dp[i] };
		while(dq.size()>1 && intersect(tmp , dq[dq.size()-2],dq[dq.size()-1]))dq.pop_back();
		dq.pb(tmp);
		ans = max(ans,dp[i]);
		/*for(auto i:dq){
			cout<<i.m<<" "<<i.k<<'\n';
		}*/
	}
	cout<<ans<<'\n';


}

