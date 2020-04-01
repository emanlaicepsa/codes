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
ll ans[20005];
int main(){
	IOS;
	ll n,q;
	cin>>n>>q;
	bitset<20005> x;
	x[10000] = 1; 
	for(int i=1,a;i<=n;i++){
		cin>>a;
		x = (x<<a) | (x>>a); 
	} 
	vector<int> v;
	for(int i=0;i<=20000;i++){
		if(x[i]) v.pb(i);
	}
	for(int i=v.size()-2;i>=0;i--){
		for(int j=v[i]+1;j<=v[i+1];j++)ans[j] = v[i+1]-10000;
	}
	for(int i=0;i<=v[0];i++)ans[i] = v[0]-10000;
	while(q--){
		cin>>n;
		cout<<ans[n+10000]<<'\n';
	}

}

