#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const ll mod=100000000;
inline ll c(ll x){
	ll a=x;
	ll b=x+1;
	ll c=2*x+1;
	if(a%3==0)a/=3;
	else if(b%3==0)b/=3;
	else c/=3;
	return (((4*(a%mod))%mod*(b%mod))%mod*(c%mod))%mod; 
}
ll fsqr(ll n){
	ll l=1;
	ll r=3037000499;
	while(l<r){
		ll m=(l+r+1)>>1;
		if(m*m>n){
			r=m-1;
		}
		else {
			l=m;
		}
	}
	return l;
}


int main(){
	ll n;
	IOS;
	while(cin>>n){
		if(n==0)break;
		
		if(!(n&1))n--;
		
		ll sqr=fsqr(n);
		
		ll left=(n-sqr*sqr);
		
		//cout<<sqr<<" "<<left<<'\n';
		
		ll ans=((sqr%mod)*((left/2+1)%mod))%mod;
		//cout<<ans<<'\n';
		ll x=((sqr-1)>>1)%mod;
		ll calc=c(x);
		//cout<<calc<<'\n';
		
		ans=(ans%mod)+calc-((x%mod)*((x+1)%mod))%mod;
		//cout<<ans<<'\n';
		
		if(!(sqr&1)){
		//	cout<<1<<'\n';
			ans+=(((sqr-1)%mod)*((sqr)%mod))%mod; 
		}
		ans%=mod;
		if(ans<0)ans+=mod;
		cout<<ans<<'\n';
	} 
}

