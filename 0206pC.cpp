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
vector<pii> v;
int ans;
int n,a,b;
bool ok(pii i,pii j){
	if((i.fi <= a&& j.fi <=a &&i.se + j.se <= b) || (i.fi <= b&& j.fi <=b &&i.se + j.se <= a))return 1;
	swap(j.fi,j.se);
	if((i.fi <= a&& j.fi <=a &&i.se + j.se <= b) || (i.fi <= b&& j.fi <=b &&i.se + j.se <= a))return 1;
	swap(i.fi,i.se);
	if((i.fi <= a&& j.fi <=a &&i.se + j.se <= b) || (i.fi <= b&& j.fi <=b &&i.se + j.se <= a))return 1;
	swap(j.fi,j.se);
	if((i.fi <= a&& j.fi <=a &&i.se + j.se <= b) || (i.fi <= b&& j.fi <=b &&i.se + j.se <= a))return 1;
	return 0;
}
int main(){
	
	cin>>n>>a>>b;
	if(a>b)swap(a,b);
	v.resize(2*n);
	for(int i=0;i<n;i++){
		cin>>v[i].fi>>v[i].se;
		v[i+n].fi = v[i].se;
		v[i+n].se = v[i].fi;
	}
	for(int i=0;i<2*n;i++){
		for(int j=0;j<2*n;j++){
			if(i%n==j%n)continue;
			if(ok(v[i],v[j])){
				ans = max(ans,v[i].fi*v[i].se + v[j].fi*v[j].se);
			} 
		}
	}
	cout<<ans<<'\n';
	


}

