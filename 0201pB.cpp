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
	ll n,m,k;
	cin>>n>>m>>k;
	m--;
	if(k<=n-1){
		cout<<1+k<<" "<<1<<'\n';
		return 0;
	}

	else{
		k-=n;
		ll x = n - k/m;
		ll y;
		if((k/m)&1){
			y = m+1 - k%m; 
		} 
		else y = 2+k%m;
		cout<<x<<" "<<y<<'\n';
	}
	



}

