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
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		ll x;
		ll sum=0;
		ll res=0;
		for(int i=0;i<n;i++){
			cin>>x;
			sum+=x;
			res^=x;
		}
		if(res*2==sum){
			cout<<0<<'\n'<<'\n';
		}
		else{
			vector<ll> v;
			v.pb(res);
			sum+=res;
			res^=res;
		//	cout<<sum<<" "<<res<<'\n';
			v.pb(sum);
			cout<<2<<'\n';
			for(auto i:v)cout<<i<<" ";
			cout<<'\n';
		}
	}



}

