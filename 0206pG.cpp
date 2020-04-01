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
int arr[505];
ll dp[505][505];
int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][i] = 1;
	}
	for(int i=1;i<=n-1;i++){
		dp[i][i+1] = 2 - (arr[i] == arr[i+1]); 
	}
	for(int l=2;l<=n-1;l++){
		for(int i=1;i+l<=n;i++){
			dp[i][i+l] = dp[i+1][i+l-1] + (arr[i]!=arr[i+l])*2;
			for(int j=i;j<i+l;j++){
				dp[i][i+l] = min(dp[i][i+l],dp[i][j] + dp[j+1][i+l]);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
		}
	}*/
	cout<<dp[1][n]<<'\n';

}

