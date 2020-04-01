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
	ll n;
	cin>>n;
	n--;
	ll now = 1;
	ll ans = 0;
	while(n){
		ans += (n+1)/2 * now;
		n/=2;
		now*=2;
	}
	cout<<ans<<'\n';

}

