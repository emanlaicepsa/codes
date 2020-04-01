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
ll arr[200005];
ll dp[200005];
int main(){
	IOS;
	int t;
	cin>>t;
	ll n,p,k;
	while(t--){
		cin>>n>>p>>k;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			dp[i]=0;
		}
		sort(arr+1,arr+1+n); 
		dp[0]=0;
		ll cmax=0;
		for(int i=1;i<=n;i++){
			if(i<k)dp[i]=dp[i-1]+arr[i];
			else dp[i]=dp[i-k]+arr[i];
			if(dp[i]<=p)cmax=i;
		}
		cout<<cmax<<'\n';
	}



}

