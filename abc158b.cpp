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
	ll n,a,b;
	cin>>n>>a>>b;
	ll ans = 0;
	ans += (n/(a+b) ) * a;
	n %=(a+b);
	ans += min(a,n);
	cout<<ans<<'\n';


}

