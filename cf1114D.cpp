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
ll dp[5005][5005];
ll arr[5005];
vector<int> v;
int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		if(i==n-1||arr[i+1]!=arr[i]){
			v.pb(arr[i]);
		}
	}
	int siz = v.size();
	
	for(int l=2;l<=siz;l++){
		for(int i=0;i+l-1<siz;i++){
			dp[i][i+l-1] = min(dp[i+1][i+l-1],dp[i][i+l-2])+1;
			if(v[i] == v[i+l-1]){
				dp[i][i+l-1] = min(dp[i][i+l-1],dp[i+1][i+l-2]+1) ;
			}
		}
	}
	

	
	cout<<dp[0][siz-1]<<'\n';

}

