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
ll arr[55][20005];
ll dp[55][20005];
ll cmax[20005];
deque<pii> dq;
ll psum[55][20005];
int main(){
	IOS;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
			psum[i][j] = psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1];
		}
	}
	for(int i=2;i<=n;i++){
		dq.clear();
		for(int j=1;j<=m;j++){
			while(!dq.empty() && dp[i-1][j] > dq.back().fi)dq.pop_back();
			dq.push_back({dp[i-1][j],j});
			cmax[j] = max(cmax[j],dp[i-1][j]);
		}
		int sub[]
		for(int j=k;j<=m;j++){
			
		}
	}
	

}

