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
ll mod,n;
ll permu[250000];
int main(){
	cin>>n>>mod;
	permu[0]=permu[1]=1;
	for(int i=2;i<=n;i++){
		permu[i]=permu[i-1]*i;
		permu[i]%=mod;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll tmp = (((n-i+1) * permu[i] % mod ) * permu[n-i] %mod)* (n-i+1) %mod;
		ans+=tmp;
		ans%=mod;
	}
	cout<<ans<<'\n';



}

