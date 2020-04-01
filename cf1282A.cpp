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
	IOS
	int t;
	cin>>t;
	ll a,b,c,d,l,r;
	while(t--){
		cin>>a>>b>>c>>d;
		if(a>b)swap(a,b);
		r=min(c+d,b);
		l=max(c-d,a);
		if(l>r)l=r;
		ll ans=b-a-(r-l);
		cout<<ans<<'\n';
	}



}

