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

int bit[200005];
int ans[200005];
int sqr;
struct q{
	int l,r,k,nm;
	q(int _l,int _r,int _k):l(_l),r(_r),k(_k){}
	q():l(0),r(0),k(0){}
	bool operator< (const q &a){
		return k<a.k;
	}
};
vector<q> v;
vector<int> pos[200005];
int arr[200005];
inline void add(int x){
	//cout<<x<<'\n';
	for(int i=x;i<=200000;i+=(i&-i)) bit[i] ++;
}
inline int que(int x){
	int ans = 0;
	for(int i=x;i;i-=(i&-i))ans += bit[i];
	return ans;
}
int main(){
	IOS;
	int n,m;
	cin>>n>>m;
	sqr = sqrt(n);
	v.resize(m);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		pos[arr[i]].pb(i);
	}
	for(int i=0;i<m;i++){
		cin>>v[i].l>>v[i].r>>v[i].k;
		v[i].nm = i;
	}
	sort(all(v));
	int now = 0;
	for(auto i:v){
		while(now <= i.k){
			for(auto j:pos[now]){
				add(j);
			}
			now ++; 
		}
		ans[i.nm] = que(i.r) - que(i.l -1);
	}
	for(int i=0;i<m;i++){
		cout<<ans[i]<<'\n';
	} 
	
}

