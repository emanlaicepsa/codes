#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll ans[1000005][2][2];
ll mod=998244353;
ll f(int l,int r,int odd){
	//cout<<l<<" "<<r<<" "<<odd<<'\n';
	if(l==r){
		if((l&1)&&odd==1)return 1;
		if(!(l&1)&&odd==0)return 1;
		return 0;
	}
	if(r-l==1)return 1;
	
	if(ans[r-l+1][l&1][odd])return ans[r-l+1][l&1][odd];
	int loog=__lg(r-l+1)+1;
	ll ta=0;
	for(int i=l+1;i<=r-1;i++){
		if(odd^(i&1))continue;
		if(__lg(i-l)+1>=loog||__lg(r-i)+1>=loog)continue;
		ta+=f(l,i-1,odd^1)*f(i+1,r,odd);
		ta%=mod;
	}
	return ans[r-l+1][l&1][odd]=ta;
}


int main(){
	int n;
	cin>>n;
	ll a=(f(1,n,0)+f(1,n,1))%mod;
	cout<<a<<'\n';



}

