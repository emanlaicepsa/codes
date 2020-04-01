#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
ll mod=1000000007;
ll dp[200][3][2];
ll godp(ll N,ll n1,ll n2){
	if(n1==3||n2==2)return 0;
	if(N==0)return 1;
	return dp[N][n1][n2]=(godp(N-1,0,n2)+godp(N-1,n1+1,n2)+godp(N-1,n1,n2+1))%mod;
}
int main(){
	ll N;
	while(cin>>N) {
		ll ans=godp(N,0,0);
		cout<<ans<<endl;
	}



}

