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
ll dp[200005];
ll ans[200005];
int cnt; 
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>dp[i];
	} 
	for(int i=n;i>=1;i--){
		if(dp[i] + i > n) ans[i] = 1;
		else ans[i] = ans[i+dp[i]] + 1;
		if(ans[i] <= k)cnt++;
		//cout<<i<<" "
	}
	cout<<cnt<<'\n';


}

