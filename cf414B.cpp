#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
ll ans[2005][2005];
const ll mod=1000000007;
int main(){
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		ans[i][1]=1; 
	}
	for(int i=1;i<k;i++){
		for(int j=1;j<=n;j++){
			ll k=1;
			while(j*k<=n){
				ans[j*k][i+1]+=ans[j][i];
				ans[j*k][i+1]%=mod;
				k++;
			}
		}
	} 
	ll a=0;
	for(int i=1;i<=n;i++){
		a+=ans[i][k];
		a%=mod;
	}
	cout<<a<<'\n';

}

