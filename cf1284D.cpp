#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define int ll
using namespace std;
using ll=long long;
using pii=pair<int,int>;
vector<pii> va,vb;
ll aa[100005],ba[100005];
bool bal[100005];
multiset<int> sa,sb;
vector<pii> na,nb;
signed main(){
	IOS
	int n;
	cin>>n;
	va.resize(n);
	vb.resize(n);
	for(int i=0;i<n;i++){
		cin>>va[i].fi>>va[i].se;
		cin>>vb[i].fi>>vb[i].se;
		na.pb({va[i].se,i});
		nb.pb({vb[i].se,i});
	}
	sort(all(na));
	sort(all(nb));
	bal[0]=1;
	for(int i=0;i<n;i++){
		//cout<<na[i].fi<<" "<<nb[i].fi<<'\n';
		if(na[i].se != nb[i].se){
			auto iter = sa.find(nb[i].se);
			if(iter!=sa.end())sa.erase(iter);
			else sb.insert(nb[i].se);
			iter = sb.find(na[i].se);
			if(iter!=sb.end())sb.erase(iter);
			else sa.insert(na[i].se);
		}
		if(sa.empty()&&sb.empty()) bal[i+1]=1;
		else bal[i+1]=0;
		//cout<<i+1<<" "<<bal[i+1]<<'\n';
	}
	// 
	
	bool ok = 1;
	for(int i=0;i<n;i++){

		aa[i] = lower_bound(all(na),make_pair(va[i].fi-1,10000000LL)) - na.begin();
		ba[i] = lower_bound(all(nb),make_pair(vb[i].fi-1,10000000LL)) - nb.begin();
		//cout<<aa[i]<<" "<<ba[i]<<'\n';
		if(aa[i]!=ba[i] || !bal[aa[i]]){
			ok = 0;
			break;
		}
	}
	
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	
	

}

