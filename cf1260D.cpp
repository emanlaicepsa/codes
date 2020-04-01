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
int m,n,k,t;
struct trap{
	int l;
	int r;
	ll d;
	bool operator<(const trap &a){
		return l==a.l ? r>a.r : l<a.l;
	}
};
vector<int> v;
vector<trap> tr;
bool cmp(int &x,int &y){
	return x>y;
}
ll dp[200005];
vector<int> in[200005];
vector<int> out[200005];
multiset<int,greater<int>> s;
bool ok(ll qq){
	s.clear();
	memset(dp,0,sizeof(dp));
	int gd = 0;
	//int idx = 0;
	int stat = 0;
	for(int i=1;i<=n+1;i++){
		stat = 0;
		for(auto x:in[i]){
			s.insert(x);
		}
		ll cm = s.size()? *s.begin():0 ;
		if(cm <= qq){
			gd = i;
			dp[i] = dp[i-1] + 1;
		}
		else{
			stat = 1;
		}
		for(auto x:out[i]){
			s.erase(s.find(x));
		}
		cm = s.size() ? *s.begin() : 0;
		if(stat && cm<=qq){
			dp[i] = dp[gd] + 3*(i-gd);
			gd = i;
		}
		else if(stat){
			dp[i] = 1e9;
		}
		//cout<<qq<<" "<<i<<" "<<dp[i]<<'\n';
	}
	return dp[n+1]<=t;
}
int main(){
	IOS;
	cin>>m>>n>>k>>t;
	v.resize(m);
	for(int i=0;i<m;i++){
		cin>>v[i];
	}
	sort(all(v),cmp);
	tr.resize(k);
	for(int i=0,a,b,c;i<k;i++){
		cin>>a>>b>>c;
		in[a].pb(c);
		out[b].pb(c);
	}
	if(!ok(v[0])){
		cout<<0<<'\n';
		return 0;
	}
	int l = 0,r = m-1;
	while(l<r){
		int mm = (l+r+1)>>1;
		if(ok(v[mm]))l=mm;
		else r=mm-1;
	} 
	cout<<l+1<<'\n';

}

