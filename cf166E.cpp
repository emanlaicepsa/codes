#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
const ll mod=1000000007;
int main(){
	ll n;
	cin>>n;
	ll ans=0;
	ll x=1;
	for(int i=1;i<n;i++){
		x*=3;
		x%=mod;
		ans=x-ans;
		ans%=mod;
	}
	if(ans<0)ans+=mod;
	cout<<ans<<'\n';


}

