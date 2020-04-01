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
struct tree{
	ll x;
	ll y;
	ll h;
	bool operator<(const tree &b){
		return (x*x+y*y==b.x*b.x+b.y*b.y) ? h >b.h :  x*x+y*y<b.x*b.x+b.y*b.y;
	}
};
vector<tree> v;
int main(){
	IOS;
	ll n;
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i].x>>v[i].y>>v[i].h;
	}
	sort(all(v));
	ll ch = 0,ans = 0;
	for(auto &i:v){
		ans = max(ans,ch - i.h);
		ch = max(ch,i.h);
	}
	cout<<ans<<'\n';


}

