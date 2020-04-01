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
ll ans;
ll le;
int main(){
	IOS;
	ll n;
	cin>>n;
	for(ll i=1,x;i<=n;i++){
		cin>>x;
		ll add = min(x/2,le);	
		
		ans += add;
		le -= add;
		x -= add*2;
		ans += x/3;
		x%=3;
		le += x;
	}
	cout<<ans<<'\n';

}

