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
ll solve(ll n,ll k){
	ll m = (1LL<<(n-1));
	if(k==m)return n;
	if(k<m)return solve(n-1,k);
	return solve(n-1,k-m);
}
int main(){
	IOS;
	ll n,k;
	cin>>n>>k;
	cout<<solve(n,k)<<'\n';


}

