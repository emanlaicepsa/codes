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
	ll t,n,g,b;
	cin>>t;
	while(t--){
		cin>>n>>g>>b;
		ll d = (n+1)/2;
		if(d <= g){
			cout<<n<<'\n';
		}
		else{
			ll round = (d-1)/g;
			ll ans = round * (g+b);
			d -= round * g;
			ans += d;
			cout<<max(ans,n)<<'\n';
		}
		
	}


}

