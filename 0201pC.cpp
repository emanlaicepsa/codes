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
	ll n,k,a,b;
	cin>>n>>k>>a>>b;
	ll ans = 0;
	if(k==1){
		cout<<(n-1)*a<<'\n';
		return 0;
	}
	while(n>1){
		if(n/k&&n%k){
			ans += (n - n/k*k )*a;
			n = n/k*k;
		}
		else if(n%k){
			ans += (n-1)*a;
			n=1;
		}
		else{
			ans += min(b,a*(n-n/k));
			n/=k;
		}
	}
	cout<<ans<<'\n';



}

