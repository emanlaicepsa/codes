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
	int t;
	cin>>t;
	while(t--){
		ll n , ans = 0;
		cin>>n;
		while(n >= 10){
			ans += n/10*10;
			n = n/10 + n%10;
		}
		ans += n;
		cout<<ans<<'\n';
	}



}

