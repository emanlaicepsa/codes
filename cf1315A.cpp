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
	ll t,a,b,c,d;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		ll ans = 0;
		ans = max((a-c-1)*b,ans);
		ans = max(c*b,ans);
		ans = max(a*d,ans);
		ans = max((b-d-1)*a,ans);
		cout<<ans<<'\n';
	} 


}

