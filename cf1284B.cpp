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
int mi[100005],mx[100005];
bool isdes[100005];
vector<int> maxx;
int descnt;
int main(){
	IOS
	ll n;
	cin>>n;
	memset(mi,0x3f,sizeof(mi));
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		int pre = 1e8 ,tmp;
		for(int j=0;j<k;j++){
			cin>>tmp;
			if(tmp>pre)isdes[i] = 1;
			mi[i] = min(tmp,mi[i]);
			mx[i] = max(tmp,mx[i]);
			pre = tmp;
		}
		if(!isdes[i])maxx.pb(mx[i]);
		else descnt++;
	}
	sort(all(maxx));
	ll ans=0;
	for(int i=0;i<n;i++){
		//cout<<isdes[i]<<" "<<mi[i]<<" "<<mx[i]<<'\n';
		if(isdes[i])ans+=n;
		else{
			ans+=maxx.end()-upper_bound(all(maxx),mi[i]);
			ans+=descnt;
		}
	}
	cout<<ans<<'\n';


}

