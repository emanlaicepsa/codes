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
ll arr[100005];
int main(){
	ll n,k,q,a,b;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	cin>>q;
	while(q--){
		cin>>a>>b;
		long double ans = upper_bound(arr,arr+n,b) - lower_bound(arr,arr+n,a);
		ans *= 100;
		ans /= n;
		cout<<fixed<<setprecision(k)<<ans<<"%\n";
	}
	


}

