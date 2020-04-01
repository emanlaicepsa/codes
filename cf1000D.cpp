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
ll dp[1005];
ll c[1005][1005];
ll pre[1005];
ll arr[1005];
const ll mod = 998244353;
int main(){
	
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<=1000;i++){
		c[i][0] = c[i][i] = 1;
	}
	for(int i=2;i<=1000;i++){
		for(int j=1;j<i;j++){
			c[i][j] = c[i-1][j-1] + c[i-1][j];
			c[i][j] %= mod;
		}
	}
	
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		arr[i]++;
	}
	
	for(int i=n;i>=1;i--){
		
		if(arr[i]>1){
			for(int j = arr[i]+i-1;j<=n;j++){
				//cout<<j<<" "<< c[j-i-1][arr[i]-2] <<" "<< (1+pre[j+1])<<'\n';
				dp[i] += c[j-i-1][arr[i]-2] * (1+pre[j+1]) %mod;
			}
		}
	//	cout<<i<<" "<<dp[i]<<'\n';
		pre[i] = pre[i+1] + dp[i];
		pre[i] %= mod;
	}
	cout<<pre[1]<<'\n';


}

