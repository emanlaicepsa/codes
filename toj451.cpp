#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const ll mod=1000000007;
vector<pii> cir;
ll power(ll x,ll t){
	ll ans=1;
	ll tem=x;
	while(t){
		if(t&1){
			ans*=tem;
			ans%=mod;
		}
		tem*=tem;
		tem%=mod;
		t>>=1;
	}
	return ans;
}
int main(){
	ll rans=0;
	ll n,m,c;
	cin>>n>>m>>c;
	ll sur=power(c,n*n);
	for(int i=1;i<=m;i++){
		if(m%i==0){
			ll tempans=power(sur,i);
			for(auto j:cir){
				if(i%j.first==0){
					tempans-=j.second;
				}
			}
			cir.emplace_back(i,tempans);
			tempans*=power(i,mod-2);
			tempans%=mod;
			rans+=tempans;
			rans%=mod;
		}
	}
	if(rans<0)rans+=mod;
	cout<<rans<<'\n';


}

