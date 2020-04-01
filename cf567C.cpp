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
map<int,ll> m[2];
int main(){
	int n,k,tmp;
	ll ans = 0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>tmp;
		if(tmp%k==0){
			ans += m[1][tmp/k];
			m[1][tmp] += m[0][tmp/k];
		}
		m[0][tmp] ++;
	}
	cout<<ans<<'\n';


}

