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
int main(){
	IOS;
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll ans = n * (n+1) / 2;
		ll x = (n-m) / (m+1);
		
		ll le = n-m;
		le -= x*(m+1);
		ans -= (x+1) * (x+2) / 2 * le;
		ans -= x * (x+1) / 2 * (m+1-le); 
		cout<<ans<<'\n';
	}


}

